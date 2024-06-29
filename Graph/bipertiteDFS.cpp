#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int color, vector<int>& col, vector<int> adj[]){
    col[node] = color;
    for (auto child : adj[node]){
        if (col[child] == -1) {
            if (dfs(child, 1 - color, col, adj) == false) return false;
        } else if (col[child] == color) return false;
    }
    return true;
}

bool isBipertite(int v, vector<int> adj[]){
    vector<int> col(v + 1, -1);
    for (int i = 1; i <= v; i++){
        if (col[i] == -1) {
            if (dfs(i, 0, col, adj) == false) return false;
        }
    }
    return true;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<int> adj[v + 1];
    while (e--){
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    if (isBipertite(v, adj))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";
    return 0;
}
