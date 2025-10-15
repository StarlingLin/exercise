#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <functional>

template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton() = default;
    ~Singleton() = default;
};

struct User
{
    std::string name;
	int age;
	User(const std::string& name, int age) : name(name), age(age) {}
};

struct Role
{
    std::string roleName; 
	Role(const std::string& roleName) : roleName(roleName) {}
};

class UserManager : public Singleton<UserManager>
{
	friend class Singleton<UserManager>;

public:
    void addUser(const std::string& name, int age)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _users.emplace_back(name, age);
    }
    void removeUser(const std::string& name)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _users.erase(std::remove_if(_users.begin(), _users.end(), [&](const User& u) { return u.name == name; }), _users.end());
    }

private:
    UserManager() = default;
    ~UserManager() = default;
    std::vector<User> _users;
    std::mutex _mutex;
};

class RoleManager : public Singleton<RoleManager>
{
    friend class Singleton<RoleManager>;
public:
    void addRole(const std::string& roleName, int level)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _roles.emplace_back(roleName, level);
    }
    void removeRole(const std::string& roleName)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _roles.erase(std::remove_if(_roles.begin(), _roles.end(), [&](const Role& r) { return r.roleName == roleName; }), _roles.end());
    }

private:
    RoleManager() = default;
    ~RoleManager() = default;
    std::vector<Role> _roles;
    std::mutex _mutex;
};