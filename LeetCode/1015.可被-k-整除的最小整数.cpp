/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */

#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start

/* BSGS O(√k)
class Solution
{
    typedef long long i64;
    typedef i64 S;

  private:
    struct G
    {
        i64 mul;
        i64 add;
    };

    i64 DiscreteLogActed(const function<G()>& e, const function<G(const G&, const G&)>& op,
                         const function<S(S, const G&)>& act, const G& x, S s, S t, i64 lower, i64 higher)
    {
        if (lower >= higher) return -1;
        const G unit = e();
        auto XPow = [&](i64 n) -> G
        {
            G p = x;
            G result = unit;
            while (n > 0)
            {
                if (n & 1LL) result = op(result, p);
                p = op(p, p);
                n /= 2;
            }
            return result;
        };
        s = act(s, XPow(lower));
        const i64 limit = higher - lower;
        const i64 K = (i64)sqrt((long double)limit) + 1;
        const S target = t;
        unordered_set<S> babyStep;
        babyStep.reserve(K);
        for (i64 step = 0; step < K; ++step)
        {
            t = act(t, x);
            babyStep.insert(t);
        }
        const G y = XPow(K);
        bool failed = false;
        for (i64 k = 0; k <= K; ++k)
        {
            const S nextBlock = act(s, y);
            if (babyStep.find(nextBlock) != babyStep.end())
            {
                for (i64 i = 0; i < K; ++i)
                {
                    if (s == target)
                    {
                        const i64 candidate = lower + k * K + i;
                        return (candidate < higher) ? candidate : -1;
                    }
                    s = act(s, x);
                }
                if (failed) return -1;
                failed = true;
            }
            s = nextBlock;
        }
        return -1;
    }

    i64 SolveAffine(i64 mul, i64 add, i64 start, i64 target, i64 mod, i64 lower)
    {
        if (start == target && lower <= 0) return 0;
        if (mul == 0)
        {
            if (add == target) return max<i64>(1, lower);
            return -1;
        }
        if (mod == 1)
        {
            if (target == 0) return max<i64>(1, lower);
            return -1;
        }
        return DiscreteLogActed([]() -> G { return {1, 0}; }, [mod](const G& g1, const G& g2) -> G
                                { return {g1.mul * g2.mul % mod, (g1.add * g2.mul + g2.add) % mod}; },
                                [mod](S state, const G& g) -> S { return (state * g.mul + g.add) % mod; }, G{mul, add},
                                start, target, lower, lower + mod);
    }

  public:
    int smallestRepunitDivByK(int k)
    {
        if (!(k % 2) || !(k % 5)) return -1;
        return SolveAffine(10, 1, 0, 0, k, 1);
    }
};
*/

// 复杂度约为O(√k)，如果用Pollard Rho在数据更大时可达O(k^0.25)
// 实际复杂度O(√K + Σ_i√(φ{p_i^{e_i}) + log^2(K))
class Solution
{
    typedef long long i64;

  private:
    // 模空间计算幂
    i64 PowMod(i64 base, i64 exp, i64 mod)
    {
        i64 result = 1 % mod;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1LL) result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
    // 质因数分解
    vector<pair<i64, int>> Factorize(i64 n)
    {
        vector<pair<i64, int>> result;
        for (i64 p = 2; p * p <= n; p += (p == 2 ? 1 : 2))
        {
            if (n % p) continue;
            int exp = 0;
            while (!(n % p))
            {
                n /= p;
                ++exp;
            }
            result.push_back({p, exp});
        }
        if (n > 1) result.push_back({n, 1});
        return result;
    }
    // 不同的质因数
    vector<i64> DistinctPF(i64 n)
    {
        vector<i64> result;
        for (const auto& [p, exp] : Factorize(n)) result.push_back(p);
        return result;
    }
    // 求10模(p^exp)的乘法阶
    // 即10^len == 1 (mod p^exp)
    i64 MulOrder10(i64 p, int exp)
    {
        i64 mod = 1;
        for (int i = 0; i < exp; ++i) mod *= p;
        // 欧拉函数φ(p^exp) = mod/p*(p-1)
        // 欧拉定理10^φ(mod) = 1 (mod mod)
        i64 order = mod / p * (p - 1);
        const vector<i64> facts = DistinctPF(order);
        for (i64 fact : facts)
            while (!(order % fact) && PowMod(10, order / fact, mod) == 1) order /= fact;
        return order;
    }

  public:
    int smallestRepunitDivByK(int k)
    {
        if (!(k % 2) || !(k % 5)) return -1;
        i64 ans = 1;
        // 各乘法阶的最小公倍数
        for (auto [p, exp] : Factorize(k))
        {
            if (p == 3) exp += 2;
            const i64 order = MulOrder10(p, exp);
            ans = lcm(ans, order);
        }
        return ans;
    }
};

// @lc code=end
