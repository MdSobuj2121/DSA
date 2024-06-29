#include <bits/stdc++.h>
using namespace std;

void BFS(int vertex, vector<int> adj[], int vis[]){
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto child: adj[node]){
            if(vis[child] == 0){
                vis[child] = 1;
                q.push(child);
            }
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
    BFS(1, adj, vis);
    return 0;
}
