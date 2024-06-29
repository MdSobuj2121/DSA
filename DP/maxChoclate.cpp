#include <bits/stdc++.h>
using namespace std;
int maxChoclate(vector<vector<int>>arr, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>>dp){
    if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return INT_MIN;
    if(i == n-1){
        if(j1 == j2) return arr[i][j1];
        else return arr[i][j1] + arr[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int mx = 0;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1 == j2) mx = max(mx, arr[i][j1] + maxChoclate(arr, n, m, i+1, j1+dj1, j2+dj2, dp));
            else mx = max(mx, arr[i][j1] + arr[i][j2] + maxChoclate(arr, n, m, i+1, j1+dj1, j2+dj2, dp));
        }
    }
    return dp[i][j1][j2] = mx;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    cout << maxChoclate(arr, n, m, 0, 0, m-1, dp);
    return 0;
}