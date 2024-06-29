#include<bits\stdc++.h>
using namespace std;
int partition(int arr[], int low, int high, int pivot){
    while(low <= high){
        while(arr[low] < pivot){
            low++;
        }
        while(arr[high] > pivot){
            high--;
        }
        if(low <= high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    return low;
}
void quickSort(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        int pivot = arr[mid];
        int index = partition(arr, low, high, pivot);
        quickSort(arr, low, index-1);
        quickSort(arr, index, high);
    }
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
    quickSort(arr, 0, n-1);
    cout << "After Sorted\n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
