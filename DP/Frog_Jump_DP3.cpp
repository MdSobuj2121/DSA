//Frog Jump DP
#include<bits/stdc++.h>
using namespace std;

int frog_jump(int n,  vector <int> &v){
    int prev2 = 0, prev = 0;
    for(int i=1; i<n; i++){
        int fs = prev + abs(v[i] - v[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(v[i] - v[i-2]);
        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    } 
    return prev;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << "Minimum Energy: " << frog_jump(n, v) << "\n";
    return 0;
}