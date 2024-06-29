#include <bits/stdc++.h>
using namespace std;
int MaxTask(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
	if(day == 0){
		int mx = 0;
		for(int task=0; task<3; task++){
			if(task != last){
				mx = max(mx, points[0][task]);
			}
		}
		return mx;
	}
	if(dp[day][last] != -1) {
		return dp[day][last];
	}
	int mx = 0;
	for(int task=0; task<3; task++){
		if(task != last){
			int point = points[day][task] + MaxTask(day-1, task, points, dp);
			mx = max(mx, point);
		}
	}
	return dp[day][last] = mx;
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
		vector<vector<int>> dp(n, vector<int>(4, -1));
        vector<vector<int>> points(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> points[i][j];
            }
        }
		cout << MaxTask(n-1, 3, points, dp) << "\n";
	}
    return 0;
}
