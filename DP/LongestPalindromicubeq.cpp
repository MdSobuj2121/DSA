#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m, vector<vector<int>> dp){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    cout << lcs(s1, s2, n, m, dp);
}