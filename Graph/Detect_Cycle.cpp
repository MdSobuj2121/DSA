#include <bits/stdc++.h>
using namespace std;
bool detectCycleBFS(vector<int> adj[], vector<bool> vis, int src){
    vis[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front(). second;
        q.pop();
        for(auto child: adj[node]){
            if(!vis[child]){
                vis[child] = true;
                q.push({child, node});
            }else{
                if(child != parent){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    vector<bool> vis(v, false);
    while(e--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int flag = 0;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(detectCycleBFS(adj, vis, i) == true){
                cout << "Cycle\n";
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) cout << "No Cycle\n";
}