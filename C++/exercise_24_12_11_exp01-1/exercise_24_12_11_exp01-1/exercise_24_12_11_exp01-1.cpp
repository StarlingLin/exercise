#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define PRIORITY(c) (\
    (c) == '{' ? 1 : \
    (c) == '[' ? 2 : \
    (c) == '(' ? 3 : \
    (c) == '<' ? 4 : \
	0)

#define MATCH(c) (\
    (c) == ')' ? '(' : \
    (c) == ']' ? '[' : \
    (c) == '}' ? '{' : \
    (c) == '>' ? '<' : \
	0)

bool Pipei(const string &str)
{
	stack<pair<char, int>> stk;
	for (char ch : str)
	{
		int pri = PRIORITY(ch);
		if (pri != 0)
		{
			if (!stk.empty() && pri <= stk.top().second)
			{
				return false;
			}
			stk.push({ ch, pri });
		}
		else
		{
			char match = MATCH(ch);
			if (match == 0)
			{
				continue;
			}
			if (stk.empty() || stk.top().first != match)
			{
				return false;
			}
			stk.pop();
		}
	}
	if (stk.empty())
	{
		return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (Pipei(str))
		{
			cout << "Match" << endl;
		}
		else
		{
			cout << "Fail" << endl;
		}
	}

	return 0;
}