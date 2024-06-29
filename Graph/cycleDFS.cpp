#include <bits/stdc++.h>
using namespace std;
bool detectCycleDFS(vector<int> adj[], vector<bool> vis, int node, int par){
    vis[node] = true;
    for(auto child: adj[node]){
        if(!vis[child]){
            if(detectCycleDFS(adj, vis, child, node) == true) return true;
        }else{
            if(child != par){
                return true;
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
            if(detectCycleDFS(adj, vis, i, -1) == true){
                cout << "Cycle\n";
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0) cout << "No Cycle\n";
}
