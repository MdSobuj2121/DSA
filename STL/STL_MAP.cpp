#include <bits/stdc++.h>
 
#define int long long
#define f first
#define s second
#define endl "\n"
#define Genshin_Start ios_base::sync_with_stdio(0), cin.tie(0)
 
using namespace std;
 
 
 
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, q, tmp;
        cin >> n >> q;
        int sum[n + 1], cnt[n + 1];
        sum[0] = 0;
        cnt[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
            cnt[i] = cnt[i - 1];
            if(tmp == 1) cnt[i]++;
        }
        while(q--) {
            int l, r;
            cin >> l >> r;
            if(l == r) {
                cout << "No" << endl;
                continue;
            }
            int su = sum[r] - sum[l - 1] - (r - l + 1);
            int tm = cnt[r] - cnt[l - 1];
            if(su < tm) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}