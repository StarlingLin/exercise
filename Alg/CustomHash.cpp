// 防止人为构造数据造成大量哈希冲突
// https://codeforces.com/blog/entry/62393

#include <chrono>
#include <cstdint>
#include <unordered_map>

using namespace std;

struct CustomHash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t, uint64_t> x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

// e.g.
int main()
{
    unordered_map<int, int, CustomHash> map1;
    unordered_map<pair<int, int>, int, CustomHash> map2;
    return EXIT_SUCCESS;
}