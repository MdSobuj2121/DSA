#include <bits/stdc++.h>
using namespace std;

vector<int> UnionTwo(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2), ans;
    for(int i=0; i<n1; i++){
        cin >> a[i];
    }
    for(int i=0; i<n2; i++){
        cin >> b[i];
    }
    ans = UnionTwo(a, b);
    int n = ans.size();
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
TC -> O(N1 + N2) 
SC -> O(N1 + N2) 
merge two sorted array
*/