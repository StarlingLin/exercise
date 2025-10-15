#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <atomic>

class ThreadPool : public std::enable_shared_from_this<ThreadPool>
{
public:
    // 获取指定键的线程池实例；如果不存在则创建
    static std::shared_ptr<ThreadPool> getInstance(const std::string& key,
        size_t thread_count = std::thread::hardware_concurrency())
    {
        std::lock_guard<std::mutex> lock(instance_mutex_);
        auto it = instances_.find(key);
        if (it != instances_.end())
        {
            return it->second;
        }
        // 使用 private 构造函数创建实例
        std::shared_ptr<ThreadPool> pool(new ThreadPool(thread_count));
        instances_[key] = pool;
        return pool;
    }

    // 禁用拷贝和赋值
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    // 添加任务到线程池
    template <typename F, typename... Args>
    void enqueue(F&& f, Args &&... args)
    {
        // 包装任务为无参函数
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            tasks_.emplace(task);
        }
        cond_.notify_one();
    }

    // 关闭线程池，等待所有线程退出
    void shutdown()
    {
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            stop_ = true;
        }
        cond_.notify_all();
        for (std::thread& worker : workers_)
        {
            if (worker.joinable())
                worker.join();
        }
    }

    ~ThreadPool()
    {
        shutdown();
    }

private:
    // 私有构造函数，仅供 getInstance 调用
    explicit ThreadPool(size_t thread_count) : stop_(false)
    {
        for (size_t i = 0; i < thread_count; ++i)
        {
            workers_.emplace_back([this] {
                while (true)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex_);
                        cond_.wait(lock, [this] { return stop_ || !tasks_.empty(); });
                        if (stop_ && tasks_.empty())
                            return;
                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    task();
                }
                });
        }
    }

    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable cond_;
    std::atomic<bool> stop_;

    // 静态成员：保存各实例
    static std::unordered_map<std::string, std::shared_ptr<ThreadPool>> instances_;
    static std::mutex instance_mutex_;
};

// 静态成员初始化
std::unordered_map<std::string, std::shared_ptr<ThreadPool>> ThreadPool::instances_;
std::mutex ThreadPool::instance_mutex_;

// 以下示例测试程序
int main()
{
    // 创建两个不同的线程池实例
    auto poolA = ThreadPool::getInstance("poolA", 3);
    auto poolB = ThreadPool::getInstance("poolB", 2);

    // 提交任务到 poolA
    for (int i = 0; i < 5; ++i)
    {
        poolA->enqueue([i] {
            std::cout << "poolA 执行任务 " << i << "，线程ID: "
                << std::this_thread::get_id() << std::endl;
            });
    }

    // 提交任务到 poolB
    for (int i = 0; i < 3; ++i)
    {
        poolB->enqueue([i] {
            std::cout << "poolB 执行任务 " << i << "，线程ID: "
                << std::this_thread::get_id() << std::endl;
            });
    }

    // 再次获取同一键，验证返回相同实例
    auto poolA2 = ThreadPool::getInstance("poolA");
    if (poolA == poolA2)
    {
        std::cout << "poolA 与 poolA2 是同一个实例" << std::endl;
    }

    // 等待一段时间让任务执行完成
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 显式关闭（也可依赖析构函数自动关闭）
    poolA->shutdown();
    poolB->shutdown();
    return 0;
}
