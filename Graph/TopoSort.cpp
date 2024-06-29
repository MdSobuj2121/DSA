#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], stack<int> &st, int vis[]){
    vis[node] = 1;
    for(auto child: adj[node]){
        if(vis[child] == 0){
            dfs(child, adj, st, vis);
        }
    }
    st.push(node);
}
vector <int> topoSort(int n, vector<int> adj[]){
    int vis[n] = {0};
    stack <int> st;
    for(int i=0; i<n; i++){
        if(vis[i] == 0){
            dfs(i, adj, st, vis);
        }
    }
    vector <int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector <int> adj[1000], ans;
    while(m--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    ans = topoSort(n, adj);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}