#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

tll ext_gcd(ll a, ll b) {
    if (b == 0) return { a, 1, 0 };
    auto [g, x1, y1] = ext_gcd(b, a % b);
    return { g, y1, x1 - (a / b) * y1 };
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> t;
    while (t--) {
        ll k, c;
        cin >> k >> c;
        // 예외
        if (c == 1) {
            if (k + 1 > 1e9) cout << "IMPOSSIBLE\n";
            else cout << k + 1 << "\n";
            continue;
        }

        if (k == 1) {
            cout << 1 << "\n";
            continue;
        }

        auto [g, x, y] = ext_gcd(k, c);
        y = (y % k + k) % k;

        if (g != 1 || y > 1e9) cout << "IMPOSSIBLE\n";
        else cout << y << "\n";
    }
    
    return 0;
}