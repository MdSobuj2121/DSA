#include <bits\stdc++.h>
using namespace std;

int cnt = 0;
int dp[100];

int fibo(int n){
    cnt++;
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2); 
}

int main(){
    for(int i=0; i<100; i++) dp[i] = -1;
    cout << fibo(16) << endl;
    cout << cnt;
}