#include <bits/stdc++.h>
using namespace std;

vector<int> dijasktra(int v, vector<vector<int>> adj[], int s) {
    //initialized with infinity
    vector<int> dist(v, INT_MAX);
    //min heap priority queue min dist will be the top most ele
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //src dist = 0
    dist[s] = 0;
    //push a pair(dist, src)
    pq.push({0, s});

    while (!pq.empty()){
        //cur node dis
        int dis = pq.top().first;
        //cur node
        int node = pq.top().second;
        //popping the ele
        pq.pop();

        //accessing all of the children of cur node
        for (auto it : adj[node]){
            //adj[node][0, 1, 2, 3...] ----> it
            //here it is a two size array
            //adj[node][0] -> {x, y} -> it[0] = x, it[1] = y
            int newnode = it[0];
            int dis1 = it[1];
            //cur node dis + childnode dis < childnode dis?
            //update childnode dis
            //push the childnode with its min dis into the pq
            if (dis + dis1 < dist[newnode]) {
                dist[newnode] = dis + dis1;
                pq.push({dist[newnode], newnode});
            }
        }
    }
    //returning the final optimal dis list
    return dist;
}

int main() {
    int v, e, s;
    cin >> v >> e >> s;
    vector<vector<int>> adj[v];
    while (e--) {
        int x, y, w;
        cin >> x >> y >> w;
        //each node containins two size array list
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    //from src to any every node min dis
    vector<int> disi = dijasktra(v, adj, s);

    //fetching those data
    for (auto it : disi) {
        cout << it << " ";
    }

    return 0;
}
