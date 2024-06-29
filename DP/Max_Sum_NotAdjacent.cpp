#include<bits/stdc++.h>
using namespace std;
int MaxSumNotAdjacent(int n, vector<int> &v, vector<int> &dp) {
    if(n == 0) return v[n];
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    int Pick = v[n] + MaxSumNotAdjacent(n-2, v, dp);
    int notPick = 0 + MaxSumNotAdjacent(n-1, v, dp);
    return dp[n] = max(Pick, notPick);
} 


//Space Optimization
int MaxSumNotAdjacentSO(vector <int> &nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int Take = nums[i]; if(i > 1) Take += prev2;
        int nonTake = 0 + prev;
        int curi = max(Take, nonTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;
    vector <int> v(n), dp(n, -1);
    for(int i=0; i<n; i++) cin >> v[i];
    //int mx = MaxSumNotAdjacent(n-1, v, dp);
    int mx = MaxSumNotAdjacentSO(v);
    cout << "MaxSum Not Adjacent: " << mx << "\n";
    return 0;
}