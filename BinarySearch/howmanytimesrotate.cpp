#include<bits/stdc++.h>
using namespace std;
int howmanyrot(vector<int> &v, int n){
    int l = 0, h = n-1;
    int mn = INT_MAX, ans = 0;
    while(l <= h){
        int mid = l + (h-l)/2;
        //left sorted
        if(v[l] <= v[mid]){
            if(mn > v[l]) {ans = l; mn = v[l];}
            l = mid + 1;
        }
        //right sorted
        else{
            if(mn > v[mid]) {ans = mid; mn = v[mid];}
            h = mid - 1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int ans = howmanyrot(v,  n);
        cout << ans << "\n";
    }
}