#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    cin >> n >> i;
    //if((n >> i)&1 == 1) cout << "YES\n";
    if((n & (1 << i)) != 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
/*
    check the i'th bit is set or not
    we can solve it using both left shift as well as right shift
    example: given n = 13 and i = 2
    n in binary 0 0 0.... 0 1 1 0 1
    1 in binary 0 0 0.... 0 0 0 0 1
    (1 << i) means 0 0 0....0 0 1 0 0 (1 left shifted two)
    formula: n & (1 << i)
    1 1 0 1
  & 0 1 0 0
-------------
   0 1 0 0 = 4 is != 0
   bit is set

*/