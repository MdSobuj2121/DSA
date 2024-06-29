#include <iostream>
using namespace std;
//Brute Force TC-> O(n^2) SC->O(1)
int missingNumber(int arr[], int n){
    int ms;
    for(int i=1; i<=n; i++){
        int flag = 0;
        for(int j=0; j<n-1; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            ms = i;
            break;
        }
    }
    return ms;
}
//Hasing TC-> O(n) SC->O(n)
int missingNumberHash(int arr[], int n){
    int ms;
    int hash[n+1];
    for(int i=0; i<n+1; i++) hash[i] = 0;
    for(int i=0; i<n-1; i++){
        hash[arr[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(hash[i] == 0){
            ms = i;
            break;
        }
    }
    return ms;
}
//more easy
int ms(int arr[], int n){
    int arrSum = 0;
    for(int i=0; i<n-1; i++){
        arrSum+= arr[i];
    }
    return (n*(n+1))/2 - arrSum;
}
//TC->O(N) SC->O(1)
int XOOR(int arr[], int n){
    int xoor1 = 0, xoor2 = 0;
    for(int i=0; i<n-1; i++){
        xoor1 = xoor1^(i+1);
        xoor2 = xoor2^arr[i];
    }
    xoor1 = xoor1^n;
    int ans =  xoor1^xoor2;
    return ans;
}
int main(){
    int n;
    cin >> n;
    int arr[n-1];
    for(int i=0; i<n-1; i++){
        cin >> arr[i];
    }
    //cout << missingNumber(arr, n) << "\n";
    //cout << missingNumberHash(arr, n) << "\n";
    //cout << ms(arr, n) << "\n";
    cout << XOOR(arr, n) << "\n";
    return 0;
}