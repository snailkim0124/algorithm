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
    for (int T = 1; T <= t; T++) {
        int a, b, c;
        string ans = "";
        cin >> a >> b >> c;

        int mx = max(a, max(b, c));
        if (mx >= a + b + c - mx) ans = "invalid!";
        else if (a == b && b == c) ans = "equilateral";
        else if ((a == b) || (b == c) || (c == a)) {
            ans = "isosceles";
        }
        else ans = "scalene";
        cout << "Case #" << T << ": " << ans << "\n";

    }

    return 0;
}