#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct Edge
{
    int to;
    int weight;
};

vector<int> dijkstra(int n, int start, const unordered_map<int, vector<Edge>>& graph)
{
    vector<int> distances(n + 1, INT_MAX);
    distances[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();
        if (current_distance > distances[current_node])
            continue;
        if (graph.find(current_node) == graph.end())
            continue;
        for (const auto& edge : graph.at(current_node))
        {
            int new_distance = current_distance + edge.weight;
            if (new_distance < distances[edge.to])
            {
                distances[edge.to] = new_distance;
                pq.push(make_pair(new_distance, edge.to));
            }
        }
    }
    return distances;
}

pair<int, string> findShortestPath(int n, int s, int t, const vector<tuple<int, int, int>>& bus_lines, const vector<tuple<int, int, int>>& metro_lines)
{
    unordered_map<int, vector<Edge>> bus_graph;
    for (const auto& line : bus_lines)
    {
        int a = get<0>(line), b = get<1>(line), c = get<2>(line);
        bus_graph[a].push_back({ b, c });
        bus_graph[b].push_back({ a, c });
    }
    vector<int> dist_from_s = dijkstra(n, s, bus_graph);

    unordered_map<int, vector<Edge>> reverse_graph;
    for (const auto& line : bus_lines)
    {
        int a = get<0>(line), b = get<1>(line), c = get<2>(line);
        reverse_graph[b].push_back({ a, c });
        reverse_graph[a].push_back({ b, c });
    }
    vector<int> dist_to_t = dijkstra(n, t, reverse_graph);

    int min_time = dist_from_s[t];
    int best_station = -1;
    for (const auto& line : metro_lines)
    {
        int x = get<0>(line), y = get<1>(line), z = get<2>(line);
        if (x == y || z <= 0)
            continue;
        if (dist_from_s[x] != INT_MAX && dist_to_t[y] != INT_MAX)
        {
            int total_time = dist_from_s[x] + z + dist_to_t[y];
            if (total_time < min_time)
            {
                min_time = total_time;
                best_station = x;
            }
        }
        if (dist_from_s[y] != INT_MAX && dist_to_t[x] != INT_MAX)
        {
            int total_time = dist_from_s[y] + z + dist_to_t[x];
            if (total_time < min_time)
            {
                min_time = total_time;
                best_station = y;
            }
        }
    }
    if (best_station == -1)
        return make_pair(min_time, "no metro");
    return make_pair(min_time, to_string(best_station));
}

int main()
{
    int n, s, t;
    while (cin >> n >> s >> t)
    {
        int m;
        cin >> m;
        vector<tuple<int, int, int>> bus_lines(m);
        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            bus_lines[i] = make_tuple(a, b, c);
        }
        int k;
        cin >> k;
        vector<tuple<int, int, int>> metro_lines(k);
        for (int i = 0; i < k; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            metro_lines[i] = make_tuple(x, y, z);
        }
        pair<int, string> result = findShortestPath(n, s, t, bus_lines, metro_lines);
        cout << result.first << endl;
        cout << result.second << endl;
    }
    return 0;
}
