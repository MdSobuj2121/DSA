#include <bits/stdc++.h>
using namespace std;
//TC->O(N^2) SC->O(1)
pair<int, int> TwoSum1(int arr[], int n, int K){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j] == K){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
//TC->O(NLogN) SC->O(1)
pair<int, int> TwoSum2(int arr[], int n, int K){
    sort(arr, arr+n);
    int l = 0, r = n-1;
    while(l < r){
        if(arr[l] + arr[r] < K){
            l++;
        }
        else if(arr[l] + arr[r] > K){
            r--;
        }
        else return {l, r};
    }
    return {-1, -1};
}
//TC->O(N) SC->O(N)
pair<int, int> TwoSum3(int arr[], int n, int K){
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int cur = arr[i];
        if(mp.find(K-cur) != mp.end()){
            return {mp[K-cur], i};
        }
        mp[cur] = i;
    }
    return {-1, -1};
}
int main(){
    int n, K;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> K;
    pair<int, int> mx1 = TwoSum1(arr, n, K);
    pair<int, int> mx3 = TwoSum3(arr, n, K);
    pair<int, int> mx2 = TwoSum2(arr, n, K);
    cout << "[";
    cout << mx1.first << " " << mx1.second << "]\n";
    cout << "[";
    cout << mx3.first << " " << mx3.second << "]\n";
    cout << "[";
    cout << mx2.first << " " << mx2.second << "]\n";
    return 0;
}
