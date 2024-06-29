#include <bits/stdc++.h>
using namespace std;
int minSum(vector<int> arr[], int i, int j, vector<int> dp[], int n){
    if(i == n-1) return arr[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = arr[i][j] + minSum(arr, i+1, j, dp, n);
    int diagonal = arr[i][j] + minSum(arr, i+1, j+1, dp, n);
    return dp[i][j] = min(down, diagonal);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr[n];
    vector<int> dp[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            dp[i].push_back(-1);
        }
    }
    cout << minSum(arr, 0, 0, dp, n);
    return 0;
}
