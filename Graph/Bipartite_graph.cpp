#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool Bipartite_BFS(int vertex, vector<int> adj[], int vis[]){
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child: adj[node]){
            if(vis[child] == -1){
                if(vis[node] == 0) vis[child] = 1;
                else vis[child] = 0;
                q.push(child);
            }else{
                if(vis[node] == vis[child]) return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertices, edges;
    cin >> vertices >> edges;
    vector <int> adj[vertices+1];
    int vis[vertices+1];
    for(int i=1; i<=vertices; i++) vis[i] = -1;
    while(edges--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //fixing for connected componnent have to write here
    bool ans = Bipartite_BFS(1, adj, vis);
    if(ans) cout << "Graph is Bipartite\n";
    else cout << "Graph is not Bipartite\n";
    return 0;
}
