#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(vis[child] == 0) dfs(child, adj, vis);
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector <int> adj[vertices];
    int vis[vertices] = {0};
    while(edges--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int nuberOfConnectedComponnent = 0;
    for(int vertex=0; vertex<vertices; vertex++){
        if(vis[vertex] == 0){
            nuberOfConnectedComponnent++;
            dfs(vertex, adj, vis);
        }
    }
    cout << "Connected Componnents are: " << nuberOfConnectedComponnent << "\n";
    return 0;
}
