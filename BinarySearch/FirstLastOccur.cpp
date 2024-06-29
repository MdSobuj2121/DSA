#include<bits/stdc++.h>
using namespace std;
pair<int, int> FirstLastOccure(vector<int> &v, int n, int tar){
    pair <int, int> res;
    res.first = -1, res.second = -1;
    int low = 0, high = n-1, lb = n, ub = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] >= tar){
            lb = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] > tar){
            ub = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    if(v[lb] == tar) res.first = lb;
    if(v[ub-1] == tar) res.second = ub-1;
    return res;
}

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int tar;
    cin >> tar;
    pair<int, int> p = FirstLastOccure(v, n, tar);
    cout << p.first << " " << p.second << "\n";
}