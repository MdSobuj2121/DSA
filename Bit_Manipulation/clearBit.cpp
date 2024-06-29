#include <bits/stdc++.h>
using namespace std;
/*
swap a and b
a = a^b
b = a^b;
a = a^b
*/
int main(){
    int n, i;
    cin >> n >> i;
    n = (n & (~(1 << i)));
    cout << n << endl;
    return 0;
}
/*

1 1 0 1
1 0 1 1
-------
1 0 0 1

*/
