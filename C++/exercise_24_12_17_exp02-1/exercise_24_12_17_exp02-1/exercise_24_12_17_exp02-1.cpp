#include <iostream>
#include <string>
#include <stack>
#include <climits>

#define ll long long
#define llmin LLONG_MIN
#define PRE(sign) (\
	(sign) == '^' ? 3 : \
	((sign) == '*' || (sign) == '/' ? 2 : \
	((sign) == '+' || (sign) == '-' ? 1 : \
	0)))

using namespace std;

bool pref(char c1, char c2)
{
	return PRE(c1) >= PRE(c2);
}

string post(string s)	//���ʽ�иĺ�
{
	string post;
	stack<char> sign;
	int i = 0;	//���ڱ����ַ���
	while (i < s.size())
	{
		if (s[i] == '(')	//������ѹջ
		{
			sign.push(s[i++]);
		}
		else if (s[i] == ')')	//�����ŵ���������
		{
			while (sign.top() != '(')
			{
				post += sign.top();
				sign.pop();
			}
			sign.pop();
			i++;
		}
		else if (isdigit(s[i]))	//����
		{
			while (i < s.size() && isdigit(s[i]))
			{
				post += s[i++];
			}
			post += ' ';
		}
		else	//�����
		{
			while (!sign.empty() && pref(sign.top(), s[i]))	//��ջ��������ȼ��ĵ���
			{
				post += sign.top();
				sign.pop();
			}
			sign.push(s[i++]);	//Ȼ����ջ
		}
	}
	while (!sign.empty())	//ʣ����ȫ����
	{
		post += sign.top();
		sign.pop();
	}
	return post;
}

ll cal(ll a, ll b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0) return llmin;
		return a / b;
	case '^':
		//��ʱ��
		//ll result = 1;
		//for (int i = 0; i < b; i++)
		//{
		//	result *= a;
		//}
		//return result;
		ll result = 1;
		while (b > 0)
		{
			if (b & 1)
			{
				result *= a;
			}
			a *= a;
			b >>= 1;
		}
		return result;
	}
}

ll calculate(string s)	//�����׺���ʽ
{
	stack<ll> val;
	for (int i = 0; i < s.size(); i++)
	{
		if (isspace(s[i]))	//�����ո�
		{
			continue;
		}
		else if (isdigit(s[i]))
		{
			string num;
			while (i < s.size() && isdigit(s[i]))
			{
				num += s[i++];
			}
			val.push(atoll(num.c_str()));
		}
		else	//������
		{
			ll n2 = val.top();
			val.pop();
			ll n1 = val.top();
			val.pop();
			ll result = cal(n1, n2, s[i]);
			if (result == llmin) return llmin;
			val.push(result);
		}
	}
	return val.top();
}

int main()
{
	string s;
	while (cin >> s)
	{
		string s_post = post(s);
		//cout << s_post << endl;
		ll result = calculate(s_post);
		if (result == llmin)
		{
			cout << "INVALID" << endl;
		}
		else
		{
			cout << result << endl;
		}
	}

	return 0;
}