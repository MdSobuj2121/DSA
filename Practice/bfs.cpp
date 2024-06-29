#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int vis[1000];
void bfs(int node){
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        for(auto child: adj[front]){
            if(vis[child] == 0){
                vis[child] = 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, e;
    cin >> n >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    return 0;
}
