#include <bits/stdc++.h>
using namespace std;

void mergetwo(int a[], int b[], int c[], int n, int m, int N){
    int i=0, j=0, k=0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    while(i < n){
        c[k++] = a[i++];
    }
    while(j < m){
        c[k++] = b[j++];
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int N = n + m;
    int a[n], b[m], c[N];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    mergetwo(a, b, c, n, m, N);
    for(int i=0; i<N; i++){
        cout << c[i] << " ";
    }
}