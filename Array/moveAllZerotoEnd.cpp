#include <bits/stdc++.h>
using namespace std;

void ZeroesEnd(int arr[], int n){
    int zeroesCnt = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) zeroesCnt++;
    }
    int k = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[k++] = arr[i];
        }
    }
    for(int i=n-zeroesCnt; i<n; i++){
        arr[i] = 0;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ZeroesEnd(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
TC -> O(N) 
SC -> O(1) 
move all zeroes to the end of the array
*/