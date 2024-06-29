#include <bits/stdc++.h>
using namespace std;
int MaxArea(vector <int> &his){
	int n = his.size();
	int maxArea = 1;
	//particular height
	for(int i=0; i<n; i++){
		int height = his[i];
		//inital left and right 
		int leftSmall = 0, rightSmall = n-1;

		//find the right smaller height
		for(int j=i+1; j<n; j++){
			if(his[j] < height){
				rightSmall = j-1;
				break;
			}
		}

		//find the left smaller height 
		for(int k=i-1; 0<=k; k--){
			if(his[k] < height){
				leftSmall = k+1;
				break;
			}
		}
		//calculate the area
		int width = (rightSmall - leftSmall + 1);
		int Area = height * width;
		//update the max area
		maxArea = max(Area, maxArea);
	}
	return maxArea;
}

int main() {
	int t;
    cin >> t;
	for(int tc=1; tc<=t; tc++){
		int n;
		cin >> n;
		vector <int> his(n);
		for(int i=0; i<n; i++){
			cin >> his[i];
		}
		int ans = MaxArea(his);
		cout << "Case " << tc << ": " << ans << "\n";
	}
    return 0;
}
