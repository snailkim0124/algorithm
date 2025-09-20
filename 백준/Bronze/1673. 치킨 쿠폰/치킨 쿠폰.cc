#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> n && cin >> k) {
        ll res = 0;
        while (1) {
            res += (n / k) * k;
            n = (n / k + n % k);
            if (n < k) {
                break;
            }
        }
        res += n;

        cout << res << "\n";
    }

    return 0;
}