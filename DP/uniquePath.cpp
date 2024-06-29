#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<vector<int>> grid, vector<vector<int>> dp){
    if(i >= 0 && j >= 0 && grid[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = func(i-1, j, grid, dp);
    int left = func(i, j-1, grid, dp);
    return dp[i][j] = up + left;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n, 0));
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    cout << func(n-1, n-1, grid, dp) << "\n";
    return 0;
}
