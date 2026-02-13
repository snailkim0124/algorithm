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
double q[505], r[505], p[505];
double pref[505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + r[i];
    }

    double sum = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = q[i] / (pref[n] - pref[i - 1]);
        sum += p[i];
    }

    cout << fixed;
    cout.precision(6);

    for (int i = 1; i <= n; i++) {
        cout << p[i] / sum << " ";
    }
    cout << "\n";


    return 0;
}