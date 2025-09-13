#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, k, s, t;
ll dp[100005][15];
vector<pll> adj[100005], rev_adj[100005];
ll ans;

ll go(int now, int cnt) {
    if (cnt > k) return -1e18;
    if (cnt == k && now == t) return 0;

    if (dp[now][cnt] != -1) return dp[now][cnt];

    ll res = -1e18;

    // 스키 코스 이동
    for (auto next : adj[now]) {
        ll tmp = go(next.first, cnt);
        if (tmp != -1e18) res = max(res, tmp + next.second);
    }

    // 리프트 이동
    if (cnt < k) {
        for (auto next : rev_adj[now]) {
            ll tmp = go(next.first, cnt + 1);
            if (tmp != -1e18) res = max(res, tmp);
        }
    }

    return dp[now][cnt] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k >> s >> t;

    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        rev_adj[b].push_back({ a, 0 });
    }

    memset(dp, -1, sizeof(dp));

    ll ans = go(s, 0);

    if (ans == -1e18) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}