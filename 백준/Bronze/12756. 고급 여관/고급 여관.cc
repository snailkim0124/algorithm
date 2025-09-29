#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int ax, ay, bx, by;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> ax >> ay >> bx >> by;

    while (1) {
        if (ay <= 0 || by <= 0) break;
        ay -= bx;
        by -= ax;
    }

    if (ay > 0) cout << "PLAYER A";
    else if (by > 0) cout << "PLAYER B";
    else cout << "DRAW";

    return 0;
}