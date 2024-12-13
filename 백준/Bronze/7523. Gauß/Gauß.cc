#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        ll n, m;
        cin >> n >> m;

        cout << "Scenario #" << i << ":\n";
        cout << (m - n + 1) * (n + m) / 2 << "\n\n";
    }
    

    return 0;
}