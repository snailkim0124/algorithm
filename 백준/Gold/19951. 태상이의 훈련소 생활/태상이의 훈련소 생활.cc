#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int h[100005];
int pref[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    while (m--) {
        int a, b, k;
        cin >> a >> b >> k;
        pref[a] += k;
        pref[b + 1] -= k;
    }

    for (int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << pref[i] + h[i] << " ";
    }
    cout << "\n";


    return 0;
}