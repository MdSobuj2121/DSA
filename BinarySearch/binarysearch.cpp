#include<bits/stdc++.h>
using namespace std;
int binary_rec(vector<int> &nums, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(nums[mid] == target) return mid;
    else if(nums[mid] < target){
        return binary_rec(nums, mid+1, high, target);
    }else{
        return binary_rec(nums, low, mid-1, target);
    }
}

int Binary_Search(vector<int> &v, int n, int target){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] == target) return mid;
        else if(v[mid] > target) high = mid-1;
        else low = mid+1;
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
        int q;
        cin >> q;
        //Query
        while(q--){
            int target ;
            cin >> target;
            int ans = binary_rec(v, 0, n-1, target);
            cout << ans << "\n";
        }
    }
}