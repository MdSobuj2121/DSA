#include<bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up += dp[i - 1][j];
                else up += 1e9;
                int left = grid[i][j];
                if(j > 0) left += dp[i][j - 1];
                else left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n-1][m-1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << func(grid, dp) << "\n";
    return 0;
}
