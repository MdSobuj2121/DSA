#include<bits/stdc++.h>
using namespace std;

//Insert Sorted Position
int lower_Bound(vector<int> &v, int n, int target){
    int low = 0, high = n-1, ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] >= target) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
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
    int target ;
    cin >> target;
    //int ans = lower_Bound(v, n, target);
    int ans = lower_bound(v.begin(), v.end(), target) - v.begin();
    cout << ans << "\n";
    }
}