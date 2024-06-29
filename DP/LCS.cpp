#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int i, int j, vector<vector<int>> dp){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return 1 + lcs(s1, s2, i-1, j-1, dp);
    else{
        int left = lcs(s1, s2, i-1, j, dp);
        int right = lcs(s1, s2, i, j-1, dp);
        return dp[i][j] = 0 + max(left, right);
    }
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout << lcs(s1, s2, n-1, m-1, dp);
}