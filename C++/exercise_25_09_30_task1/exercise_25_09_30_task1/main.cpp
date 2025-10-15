#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <functional>

struct User 
{
    const std::string  name;
    int age;
};

class UserManager
{
public:
	static UserManager& getInstance()
	{
		static UserManager instance;
		return instance;
	}
	void addUser(const std::string& name, int age)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		users.push_back(new User{ name, age });
	}
	void removeUser(const std::string& name)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		for (auto it = users.begin(); it != users.end(); ++it)
		{
			if ((*it)->name == name)
			{
				delete* it;
				users.erase(it);
				break;
			}
		}
	}
	void listAll(std::function<void(User*)> callback) const
	{
		std::lock_guard<std::mutex> lock(_mutex);
		for (User* user : users)
		{
			callback(user);
		}
	}
	~UserManager()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		for (User* user : users)
		{
			delete user;
		}
		users.clear();
	}

private:
	mutable std::mutex _mutex;
	UserManager() {};
	std::vector<User*> users;
};

void threadTest(int id)
{
	UserManager& mgr = UserManager::getInstance();
	for (int i = 0; i < 5; ++i)
	{
		mgr.addUser("Thread" + std::to_string(id) + "_" + std::to_string(i), 20 + i);
	}
	mgr.listAll([](User* p) { std::cout << p->name << " " << p->age << std::endl; });
}

int main()
{
    UserManager& mgr = UserManager::getInstance();
    mgr.addUser("张三", 18);
    mgr.addUser("李四", 19);
    mgr.addUser("王五", 18);
    mgr.removeUser("李四");
    mgr.addUser("赵六", 20);
    mgr.listAll([](User* p) { std::cout << p->name << " " << p->age << std::endl; });

	std::cout << "多线程测试" << std::endl;
	std::vector<std::thread> threads;
	threads.reserve(3);
	for (int i = 0; i < 3; ++i)
	{
		threads.emplace_back(threadTest, i);
	}
	for (auto& t : threads)
	{
		t.join();
	}
	return 0;
}