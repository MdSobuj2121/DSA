#include <iostream>
using namespace std;
//TC->O(N) SC->O(N)
int MaxConsecutiveOne(int arr[], int n){
    int mx = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            cnt++;
            mx = max(cnt, mx);
        }else{
            cnt = 0;
        }
    }
    return mx;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << MaxConsecutiveOne(arr, n) << "\n";
}