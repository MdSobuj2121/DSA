#include <bits/stdc++.h>
using namespace std;

int uniquePaths1(int i, int j, vector<vector<int>>&dp){
    if(i == 0 && j == 0) {
        return 1;
    }
    if(i < 0 || j < 0) {
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = uniquePaths1(i-1, j, dp);
    int left = uniquePaths1(i, j-1, dp);
    return dp[i][j] = up + left;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int UniquePath = uniquePaths1(m-1, n-1, dp);
        cout << UniquePath << "\n";

        /*
        Tabulation
        -----------
        int dp[m][n];
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int up = 0, left = 0;
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        cout << dp[m-1][n-1] << "\n";
        */

       /*
       More Space Optimization
       -----------------
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    cur[j] = 1;
                }
                else{
                    if(i > 0){
                        up = prev[j];
                    }
                    if(j > 0){
                        left = cur[j-1];
                    }
                    cur[j] = up + left;
                }
            }
            prev = cur;
        }
        cout << prev[n-1] << "\n";
       */
    }
    return 0;
}