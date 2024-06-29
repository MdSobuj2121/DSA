#include <bits/stdc++.h>
using namespace std;
const long long int inf = 999999;
void bfs(vector<int>& vis, vector<int>& dis, vector<vector<pair<int, int>>>& adj) {
    vis[0] = 1;
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto& edge : adj[node]) {
            int child = edge.first;
            int weight = edge.second;
            if (vis[child] == 0){
                dis[child] = min(dis[child], dis[node] + weight);
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    for (int i = 0; i < dis.size(); i++) {
        cout << i << "->" << dis[i] << endl;
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> adj(nodes);
    vector<int> dis(nodes, inf), vis(nodes, 0);
    for (int i = 0; i < edges; i++) {
        int weight, u, v;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    bfs(vis, dis, adj);
    return 0;
}
