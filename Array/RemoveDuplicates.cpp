#include <bits/stdc++.h>
using namespace std;
//TC -> O(N);
//SC -> O(1);
//Remove Duplicates from Sorted Array
int removeduplicates(int arr[], int n){
    if(n == 1) return 1;
    int k=1;
    int prev = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] != prev){
            arr[k++] = arr[i];
            prev = arr[i];
        }
        else{
            continue;
        }
    }
    return k;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ansIndx = removeduplicates(arr, n);
    for(int i=0; i<ansIndx; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
