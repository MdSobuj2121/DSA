#include<bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2 = "Samsung";
    cin >> s1;
    int initialJ = 0, cnt = 0;
    int n = s2.size(), m = s1.size();
    for(int i=0; i<n; i++){
        bool temp = false;
        for(int j=initialJ; j<m; j++){
            if(s2[i] == s1[j]){
                cnt++;
                initialJ = j+1;
                temp = true;
                break;
            }
        }
        if(!temp) break;
    }
    if(cnt == 7) cout << "SRBD\n";
    else cout << "GHOST\n";
    return 0;
}
