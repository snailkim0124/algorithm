#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll A, N;
ll ans1, ans2;

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

    ll x, y;
    cin >> N >> A;

    ans1 = N - A;

    ll GCD = ext_gcd(A, N, x, y);

    //cout << "gcd : " << GCD << "\n";
    //cout << "a : n : x : y" << "\n";
    //cout << A << " : " << N << " : " << x << " : " << y << "\n";
    
    if (GCD != 1) ans2 = -1;
    else ans2 = (x % N + N) % N;

    cout << ans1 << " " << ans2 << "\n";
    
    return 0;
}