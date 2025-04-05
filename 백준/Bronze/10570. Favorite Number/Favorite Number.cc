#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while (t--) {
        int cnt[1005] = { 0 };
        int v;
        int mx = -1, ans = 0;
        cin >> v;
        while(v--) {
            int num;
            cin >> num;
            cnt[num]++;
        }

        for (int i = 0; i <= 1005; i++) {
            if (mx < cnt[i]) {
                mx = cnt[i];
                ans = i;
            }
        }

        cout << ans << "\n";
    }
    
    
    return 0;
}