#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;


const ll mod = 1000000007;
ll dp[55][55][55][55];

ll go(ll s, ll a, ll b, ll c) {
    if (s == 0) {
        return (a == 0 && b == 0 && c == 0);
    }
    if (a < 0 || b < 0 || c < 0) return 0;
    if (dp[s][a][b][c] != -1) return dp[s][a][b][c];

    ll ans = 0;
    ans += go(s - 1, a - 1, b, c) % mod;
    ans += go(s - 1, a, b - 1, c) % mod;
    ans += go(s - 1, a, b, c - 1) % mod;
    ans += go(s - 1, a - 1, b - 1, c) % mod;
    ans += go(s - 1, a - 1, b, c - 1) % mod;
    ans += go(s - 1, a, b - 1, c - 1) % mod;
    ans += go(s - 1, a - 1, b - 1, c - 1) % mod;
    return dp[s][a][b][c] = ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll s, a, b, c;
    cin >> s >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << go(s, a, b, c) << "\n";

    return 0;
}