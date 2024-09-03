/*
    My own implementation

    Note that djikstra fails in case of negative cycles
*/

#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<int> AllShortestPathsFromSource(int n, vector<vector<pair<int, int>>> &edges, int s) {
    vector<int> costs(n, INF);
    costs[s] = 0;

    std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (q.size()) {
        // current cost, current node
        auto [ccost, cnode] = q.top();
        q.pop();

        if (ccost > costs[cnode]) continue;
        
        // neighbor cost, neighbor node
        for (auto [nnode, ncost] : edges[cnode]) {
            if (ncost + ccost < costs[nnode]) {
                costs[nnode] = ncost + ccost;
                q.push({costs[nnode], nnode});
            }
        }
    }

    for (auto &i : costs) {
        if (i == INF) i = -1;
    }

    return costs;
}