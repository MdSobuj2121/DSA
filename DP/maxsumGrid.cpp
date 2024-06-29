#include <bits/stdc++.h>
using namespace std;
int MaxSum(vector<vector<int>> arr, int n, int m, int i, int j, vector<vector<int>> dp){
    if(j < 0 || j >= m) return INT_MIN;
    if(i == n-1) return arr[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int d = arr[i][j] + MaxSum(arr, n, m, i+1, j, dp);
    int l = arr[i][j] + MaxSum(arr, n, m, i+1, j-1, dp);
    int r = arr[i][j] + MaxSum(arr, n, m, i+1, j+1, dp);
    return dp[i][j] = max(d, max(l, r));
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m, 0));
    vector<vector<int>> dp(n, vector<int> (m, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int mx = INT_MIN;
    for(int i=0; i<m; i++){
        mx = max(mx, MaxSum(arr, n, m, 0, i, dp));
    }
    cout << mx;
    return 0;
}