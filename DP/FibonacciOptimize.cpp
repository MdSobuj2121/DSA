#include <bits\stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int prev2 = 0;
    int prev = 1;
    int curi;
    for(int i=2; i<=n; i++){
        curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout << prev;
}
