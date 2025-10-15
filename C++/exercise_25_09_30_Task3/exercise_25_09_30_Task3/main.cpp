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
    // ��ȡָ�������̳߳�ʵ��������������򴴽�
    static std::shared_ptr<ThreadPool> getInstance(const std::string& key,
        size_t thread_count = std::thread::hardware_concurrency())
    {
        std::lock_guard<std::mutex> lock(instance_mutex_);
        auto it = instances_.find(key);
        if (it != instances_.end())
        {
            return it->second;
        }
        // ʹ�� private ���캯������ʵ��
        std::shared_ptr<ThreadPool> pool(new ThreadPool(thread_count));
        instances_[key] = pool;
        return pool;
    }

    // ���ÿ����͸�ֵ
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    // ��������̳߳�
    template <typename F, typename... Args>
    void enqueue(F&& f, Args &&... args)
    {
        // ��װ����Ϊ�޲κ���
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            tasks_.emplace(task);
        }
        cond_.notify_one();
    }

    // �ر��̳߳أ��ȴ������߳��˳�
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
    // ˽�й��캯�������� getInstance ����
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

    // ��̬��Ա�������ʵ��
    static std::unordered_map<std::string, std::shared_ptr<ThreadPool>> instances_;
    static std::mutex instance_mutex_;
};

// ��̬��Ա��ʼ��
std::unordered_map<std::string, std::shared_ptr<ThreadPool>> ThreadPool::instances_;
std::mutex ThreadPool::instance_mutex_;

// ����ʾ�����Գ���
int main()
{
    // ����������ͬ���̳߳�ʵ��
    auto poolA = ThreadPool::getInstance("poolA", 3);
    auto poolB = ThreadPool::getInstance("poolB", 2);

    // �ύ���� poolA
    for (int i = 0; i < 5; ++i)
    {
        poolA->enqueue([i] {
            std::cout << "poolA ִ������ " << i << "���߳�ID: "
                << std::this_thread::get_id() << std::endl;
            });
    }

    // �ύ���� poolB
    for (int i = 0; i < 3; ++i)
    {
        poolB->enqueue([i] {
            std::cout << "poolB ִ������ " << i << "���߳�ID: "
                << std::this_thread::get_id() << std::endl;
            });
    }

    // �ٴλ�ȡͬһ������֤������ͬʵ��
    auto poolA2 = ThreadPool::getInstance("poolA");
    if (poolA == poolA2)
    {
        std::cout << "poolA �� poolA2 ��ͬһ��ʵ��" << std::endl;
    }

    // �ȴ�һ��ʱ��������ִ�����
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // ��ʽ�رգ�Ҳ���������������Զ��رգ�
    poolA->shutdown();
    poolB->shutdown();
    return 0;
}
