// 求解集合S在幺半群X上的离散对数
// https://github.com/981377660LMT/algorithm-study/blob/master/19_%E6%95%B0%E5%AD%A6/%E6%95%B0%E8%AE%BA/BSGS/DiscreteLog/DiscreteLogActed.go

#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_set>

using namespace std;

typedef long long i64;
typedef i64 S; // 序列中的一个状态

// 记录一次仿射变换 f(n) = mul*n+add (mod m)
struct G
{
    i64 mul;
    i64 add;
};

/// @brief 求集合S在幺半群X上的离散对数（从状态s最少进行多少次变换x能到达状态t）
/// @param e 幺半群X的单位元：什么都不做的单位变换
/// @param op 幺半群X的结合律：合并op(g1,g2)就是先g1再g2
/// @param act 幺半群X在集合S上的作用，act(st,g)就是对st做变换g
/// @param x 每一步变换
/// @param s 起始状态
/// @param t 目标状态
/// @param lower 查找范围下界
/// @param higher 查找范围上界
/// @return 满足act(s,x^n)==t的最小n
i64 DiscreteLogActed(const function<G()>& e, const function<G(const G&, const G&)>& op,
                     const function<S(S, const G&)>& act, const G& x, S s, S t, i64 lower, i64 higher)
{
    if (lower >= higher) return -1; // 搜索区间空
    const G unit = e();             // 单位变换（对于仿射是f(n)=n，也就是G{1,0}）
    // 快速幂求x^n，即总变换
    auto XPow = [&](i64 n) -> G
    {
        G p = x; // x,x2,x4,x8...
        G result = unit;
        while (n > 0)
        {
            if (n & 1LL) result = op(result, p);
            p = op(p, p);
            n /= 2;
        }
        return result;
    };
    s = act(s, XPow(lower));                         // 初态为查找下界
    const i64 limit = higher - lower;                // 查找总长
    const i64 K = (i64)sqrt((long double)limit) + 1; // BSGS分块长
    const S target = t;                              // 保存一下目标状态，马上建表会改变t
    unordered_set<S> babyStep;                       // 小步哈希表保存从目标t走1~K步状态
    babyStep.reserve(K);
    for (i64 step = 0; step < K; ++step)
    {
        t = act(t, x); // act(t),act2(t)...actK(t)
        babyStep.insert(t);
    }
    const G y = XPow(K);         // 一次进行K步的变换 y = x^K
    bool failed = false;         // 幺半群不一定有逆元，可能假匹配
    for (i64 k = 0; k <= K; ++k) // 大步查找，每次循环处理一个长度K的块
    {
        const S nextBlock = act(s, y); // 下一个块的起点
        // 外层按块从小到大检查，内层按位置从小到大检查，第一个candidate就是最小满足
        // 目标在当前块=>nextBlock在表中：
        // 设目标在当前块i位置Fi(s)=target => FK(s) = F(K-i)(target)
        if (babyStep.find(nextBlock) != babyStep.end())
        {
            for (i64 i = 0; i < K; ++i) // 目标可能在当前块
            {
                if (s == target) // 找到目标
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
    return DiscreteLogActed([]() -> G { return {1, 0}; },        // 幺半群X的单位元，返回单位变换
                            [mod](const G& g1, const G& g2) -> G // 幺半群X的结合律，返回合并仿射
                            { return {g1.mul * g2.mul % mod, (g1.add * g2.mul + g2.add) % mod}; },
                            [mod](S state, const G& g) -> S            // 幺半群X在集合S上的作用
                            { return (state * g.mul + g.add) % mod; }, //
                            G{mul, add}, start, target, lower,
                            lower + mod // 搜索上界，一共mod个可能状态
    );
}

// 1015. 可被整除的最小整数
// 序列1,11,111...中能被k整除的最小项的索引？
// X[i] = (10*X[i-1]+1) mod k
// mul=10,add=1,start=0,target=0,mod=k,lower=1
void lc1015()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 mod;
    cin >> mod;
    cout << SolveAffine(10, 1, 0, 0, mod, 1) << endl;
}

void abc222_g()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;
    cin >> cnt;
    while (cnt--)
    {
        i64 mod;
        cin >> mod;
        cout << SolveAffine(10, 2, 0, 0, mod, 1) << endl;
    }
}

int main()
{
    abc222_g();
    return EXIT_SUCCESS;
}