#include <bits/stdc++.h>
using namespace std;
//tc->O(N^2) sc->O(1)
int longSubK(int arr[], int n, int K){
    int len = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == K){
                len = max(len, (j-i+1));
            };
            if(sum > K) break;
        }
    }
    return len;
}
//tc->O(nlogn) sc->O(n)
int longSubK1(int arr[], int n, int K){
    int mxlen = 0, sum = 0;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == K){
            mxlen = max(mxlen, i+1);
        }
        int rem = sum - K;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            mxlen = max(mxlen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return mxlen;
}
int main(){
    int n, K;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> K;
    int mx = longSubK1(arr, n, K);
    cout << mx << "\n";
    return 0;
}