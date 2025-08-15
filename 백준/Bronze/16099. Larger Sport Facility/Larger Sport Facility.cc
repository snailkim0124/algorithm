#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a * b > c * d) cout << "TelecomParisTech\n";
        else if (a * b == c * d) cout << "Tie\n";
        else cout << "Eurecom\n";
    }
    

    return 0;
}