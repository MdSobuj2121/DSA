#include <bits/stdc++.h>
using namespace std;
int maxwindow(vector<int> a, int n, int k){
    int sum = 0, l = 0, r = k-1;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    int mx = sum;
    while(r < n-1){
        sum -= a[l];
        l++;
        r++;
        sum += a[r];
        mx = max(mx, sum);
    }
    return mx;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << maxwindow(a, n, k);
    return 0;
}
