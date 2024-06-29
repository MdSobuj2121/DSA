#include <bits/stdc++.h>
using namespace std;

void LeftRotate(int arr[], int n, int k){
    int temp[k];
    for(int i=0; i<k; i++){
        temp[i] = arr[i];
    }
    for(int i=k; i<n; i++){
        arr[i-k] = arr[i];
    }
    int newindx = 0;
    for(int i=n-k; i<n; i++){
        arr[i] = temp[newindx++];
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    LeftRotate(arr, n, k);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
TC -> O(N) 
SC -> O(1) 
Left Rotate k places of The Given Array
*/