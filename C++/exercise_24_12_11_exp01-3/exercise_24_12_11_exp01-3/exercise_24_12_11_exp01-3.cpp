#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    for (int i = 0; i < n; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    for (int i = 0; i < n; ++i)
    {
        if (!graph[i].empty())
        {
            cout << i << ":";
            for (const auto& edge : graph[i])
            {
                cout << "(" << i << "," << edge.first << "," << edge.second << ")";
            }
            cout << endl;
        }
    }

    return 0;
}
