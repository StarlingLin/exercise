#define _CRT_SECURE_NO_WARNINGS

//光、对立两人和小红对战
//每一轮光先对小红攻击，对立后对小红攻击，然后小红展开幻术，使光和对立互相攻击
//对立的攻击力是a，光的攻击力是b
//对立的生命值是h，光的生命值是k
//小红不会死，而光和对立若某一人死亡而另外一人存活，则存活者会对小红发起一次10倍攻击并死亡
//求最终两人可以对小红造成的伤害

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//运行超时
int main() 
{
	long long a, b, h, k;
	cin >> a >> h >> b >> k;
	long long damage = 0;
	while (h > 0 && k > 0) 
	{
		damage += a + b;
		h -= b;
		if (h <= 0) {
			damage += 10 * b;
			break;
		}
		k -= a;
		if (k <= 0) {
			damage += 10 * a;
			break;
		}
	}
	cout << damage << endl;
	return 0;
}