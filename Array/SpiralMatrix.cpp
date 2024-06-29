#include <bits/stdc++.h>
using namespace std;
vector<int> SpiralMat(vector<vector<int>> &mat){
    vector<int> sp;
    int n = mat.size();
    int m = mat[0].size();
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;
    while(left <= right && top <= bottom){

        for(int i=left; i<=right; i++){
            sp.push_back(mat[top][i]);
        }
        top++;

        for(int i=top; i<= bottom; i++){
            sp.push_back(mat[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i=right; i >= left; i--){
                sp.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i >= top; i--){
                sp.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return sp;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    vector<int> spiral = SpiralMat(mat);
    for(auto ele: spiral){
        cout << ele << " ";
    }
    return 0;
}
