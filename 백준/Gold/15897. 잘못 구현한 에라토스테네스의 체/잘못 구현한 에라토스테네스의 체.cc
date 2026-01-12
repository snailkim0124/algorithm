#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int sieve[10005];
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    ll res = n;
    ll m = n - 1;

    for (ll i = 1; i <= m;) {
        ll q = m / i;
        ll j = m / q;

        res += (j - i + 1) * q;

        i = j + 1;
    }

    cout << res << "\n";

    
    return 0;
}