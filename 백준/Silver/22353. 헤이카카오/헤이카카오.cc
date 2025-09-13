#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double a, d, k;
double res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> d >> k;
    d *= 0.01;
    k *= 0.01;
    double round = 1;
    double now = d;
    double lose = 1; // 졌을 때

    while (1) {
        res += a * round++ * lose * now;
        lose *= (1.00 - now);
        now += now * k;

        if (now >= 1.00) {
            res += a * round++ * lose;
            break;
        }
    }

    cout << fixed;
    cout.precision(6);

    cout << res << "\n";
    

    return 0;
}