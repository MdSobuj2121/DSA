#include<bits\stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high){
    int Newarr[high-low+1];
    int left = low;
    int right = mid+1;
    int newIndex = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            Newarr[newIndex] = arr[left];
            left++;
        }
        else{
            Newarr[newIndex] = arr[right];
            right++;
        }
        newIndex++;
    }
    while(left <= mid){
        Newarr[newIndex] = arr[left];
        left++;
        newIndex++;
    }
    while(right <= high){
        Newarr[newIndex] = arr[right];
        right++;
        newIndex++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = Newarr[i-low];
    }
}
void mergeSort(int arr[], int low, int high){
    if(low >= high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Before Sorted\n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    mergeSort(arr, 0, n-1);
    cout << "After Sorted\n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}