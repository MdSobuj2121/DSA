#include<bits/stdc++.h>
using namespace std;
int minSortRot(vector<int> &v, int n){
    int l = 0, h = n-1;
    int mn = INT_MAX;
    while(l <= h){
        int mid = l + (h-l)/2;
        //left sorted
        if(v[l] <= v[mid]){
            mn = min(mn, v[l]);
            l = mid + 1;
        }
        //right sorted
        else{
            mn = min(mn, v[mid]);
            h = mid - 1;
        }
    }
    return mn;
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
        int ans = minSortRot(v,  n);
        cout << ans << "\n";
    }
}