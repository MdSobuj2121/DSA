#include <bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int n, int i){
    if(i == n/2) return;
    swap(arr[i], arr[n-i-1]);
    return reverseArray(arr, n, i+1);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    reverseArray(arr, n, 0);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}