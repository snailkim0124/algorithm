#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

//const double PI = 3.1415926535;

void solve() {
    double b, w;
    cin >> b >> w;

    double sum = 0;
    for (int i = 0; i < b; i++) {
        double num;
        cin >> num;
        sum += 4 * M_PI * (num * num * num) / 3000.0;
    }

    //sum /= 1000;

    //cout << sum << " " << w << "\n";
    cout << (sum >= w ? "Yes" : "No") << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt;
    cin >> tt;
    for (int T = 1; T <= tt; T++) {
        cout << "Data Set " << T << ":\n";
        solve();

        cout << "\n";

    }
    
    return 0;
}