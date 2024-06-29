//Frog Jump DP
#include<bits/stdc++.h>
using namespace std;

int frog_jump(int n, vector<int> &v, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int right = INT_MAX;
    int left = frog_jump(n-1, v, dp) + abs(v[n] - v[n-1]);
    if(n > 1){
        right = frog_jump(n-2, v, dp) + abs(v[n] - v[n-2]);
    }
    return dp[n] = min(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n), dp(n+1, -1);
    for(int i=0; i<n; i++) cin >> v[i];
    int mn = frog_jump(n-1, v, dp);
    cout << "Minimum Energy: " << mn << "\n";
    return 0;
}