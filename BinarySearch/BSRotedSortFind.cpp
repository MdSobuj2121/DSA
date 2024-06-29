#include<bits/stdc++.h>
using namespace std;
int bsrotate(vector<int> &v, int n, int target){
    int l = 0, h = n-1;
    while(l <= h){
        int mid = l + (h-l)/2;
        if(v[mid] == target) return mid;
        if(v[l] == v[mid] && v[mid] == v[h]){
            l++;
            h--;
            continue;
        }
        //left sorted
        if(v[l] <= v[mid]){
            if(v[l] <= target && target <= v[mid]){
                h = mid - 1;
            }
            else l = mid + 1;
        }
        //right sorted
        else{
            if(v[mid] <= target && target <= v[h]){
                l = mid + 1;
            }
            else h = mid - 1;
        }
    }
    return -1;
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
        int ans = bsrotate(v,  n, target);
        cout << ans << "\n";
    }
}