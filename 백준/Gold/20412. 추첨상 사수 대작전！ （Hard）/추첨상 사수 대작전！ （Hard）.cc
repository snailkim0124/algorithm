#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll m, seed, x1, x2;

ll mk_pos(ll num) {
    return num < 0 ? num + m : num;
}

ll divide_pow(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k % 2 == 1) res = (res * n) % m;
        n = (n * n) % m;
        k /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> m >> seed >> x1 >> x2;

    ll a = (x2 - x1) % m;
    a = mk_pos(a);
    ll b = (x1 - seed) % m;
    b = mk_pos(b);

    a = (a * divide_pow(b, m - 2) % m);

    ll c = (x2 - a * x1) % m;
    c = mk_pos(c);

    cout << a << " " << c;

    
    return 0;
}