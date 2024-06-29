//Frog Jump DP
#include<bits/stdc++.h>
using namespace std;

int frog_jump(int n, vector <int> &dp, vector <int> &v){
    for(int i=1; i<n; i++){
        int fs = dp[i-1] + abs(v[i] - v[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(v[i] - v[i-2]);
        dp[i] = min(fs, ss);
    } 
    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 0);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << "Minimum Energy: " << frog_jump(n, dp, v) << "\n";
    return 0;
}