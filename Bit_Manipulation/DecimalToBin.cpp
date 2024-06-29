#include <bits/stdc++.h>
using namespace std;

string dectobin(int n){
    string bin = "";
    if(n == 0) return "0000";
    while(n != 1){
        int rem = n%2;
        if(rem == 1) bin += '1';
        else bin += '0';
        n /= 2;
    }
    bin += "1";
    reverse(bin.begin(), bin.end());
    if(bin.size() == 1) bin = "000" + bin;
    if(bin.size() == 2) bin = "00" + bin;
    if(bin.size() == 3) bin = "0" + bin;
    return bin;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<=n; i++){
        string bin = dectobin(i);
        cout << bin << endl;
    }
    return 0;
}