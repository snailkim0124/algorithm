#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, n, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    cin >> n;
    while (n--) {
        int f;
        cin >> f;
        sum += f;
    }

    cout << ((sum >= t) ? "Padaeng_i Happy" : "Padaeng_i Cry");

    return 0;
}