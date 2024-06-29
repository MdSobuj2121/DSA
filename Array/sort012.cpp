#include <bits/stdc++.h>
using namespace std;
void sort012(int arr[], int n){
    int zero = 0, one = 0, two = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) zero++;
        if(arr[i] == 1) one++;
        if(arr[i] == 3) two++;
    }
    for(int i=0; i<zero; i++){
        arr[i] = 0;
    }
    for(int i=zero; i<zero+one; i++){
        arr[i] = 1;
    }
    for(int i=zero+one; i<n; i++){
        arr[i] = 2;
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort012(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
