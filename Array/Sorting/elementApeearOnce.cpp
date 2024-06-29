#include<bits/stdc++.h>
using namespace std;
//TC->O(N^2) SC->O(1)
int OccureOnce(int arr[], int n){
    int ans;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == arr[i]){
                cnt++;
            }
        }
        if(cnt == 1){
            ans = arr[i];
        }
    }
    return ans;
}
//TC->O(N) SC->O(1)
int OccureOnce1(int arr[], int n){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    int ans;
    for(auto it: mp){
        if(it.second == 1){
            ans = it.first;
            break;
        }
    }
    return ans;
}
//Optimal TC->O(N) SC->O(1)
int XOR(int arr[], int n){
    int xor = 0;
    for(int i=0; i<n; i++){
        xor = xor^arr[i];
    }
    return xor;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << XOR(arr, n) << "\n";
}