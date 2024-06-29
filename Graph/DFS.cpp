#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex, vector<int> adj[], int vis[]){
    vis[vertex] = 1;
    cout << vertex << " ";
    for(auto child: adj[vertex]){
        if(vis[child] == 0){
            DFS(child, adj, vis);
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector <int> adj[vertices+1];
    int vis[vertices+1] = {0};
    while(edges--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1, adj, vis);
    return 0;
}
