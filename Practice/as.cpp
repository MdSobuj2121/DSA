#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 1e9;

int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char direction[] = {'D', 'U', 'R', 'L'};
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int bfs(int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        if (x == ex && y == ey) return dist[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return INF;
}

int main() {
    cin >> n >> m;
    int startX, startY, endX, endY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }

    int shortestPathLength = bfs(startX, startY, endX, endY);
    if (shortestPathLength != INF) {
        cout << "YES" << endl;
        cout << shortestPathLength << endl;

        string path = "";
        int x = endX, y = endY;
        while (x != startX || y != startY) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny) && dist[nx][ny] == dist[x][y] - 1) {
                    path = direction[i] + path;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }

        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}