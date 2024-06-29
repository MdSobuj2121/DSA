#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(int a[], int n){
    for(int i=0; i<n/2; i++){
        if(a[i] != a[n-1-i]) return false;
    }
    return true;
}
string revString(string str){
    for(int i=0; i<str.size()/2; i++){
        char tmp = str[i];
        str[i] = str[str.size()-1-i];
        str[str.size()-1-i] = tmp;
    }
    return str;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    if(is_palindrome(a, n)) cout << "YES\n";
    else cout << "NO\n";
    string str;
    cin >> str;
    cout << revString(str) << "\n";
    if(str == revString(str)) cout << "YES\n";
    else cout << "NO\n"; 
    return 0;
}
//TC -> O(N)
