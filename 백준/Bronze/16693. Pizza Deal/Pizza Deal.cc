#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double PI = 3.1415926535;
double a, b, c, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c >> d;
    double w1 = a / b;
    double w2 = (c * c * PI) / d;

    if (w2 > w1) cout << "Whole pizza\n";
    else cout << "Slice of pizza\n";

    return 0;
}