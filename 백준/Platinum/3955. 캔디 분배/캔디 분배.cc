#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

// 확장 유클리드 호제법
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> t;
    while (t--) {
        ll k, c, x, y;
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


        ll GCD = ext_gcd(k, c, x, y);
        ll ans = (y % k + k) % k;
        
        if (GCD != 1 || ans > 1e9) cout << "IMPOSSIBLE\n"; // 모듈러 역원이 존재 X
        else cout << ans << "\n";
    }
    
    
    return 0;
}