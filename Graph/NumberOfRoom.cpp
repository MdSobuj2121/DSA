#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int x, int y){
    visited[x][y] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '.' && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}
int main(){
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    visited.assign(n, vector<bool> (m, false));
    int room = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                dfs(i, j);
                room++;
            }
        }
    }
    cout << room << "\n";
    return 0;
}
