#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    if (a == b && b == c) cout << "*";
    else if (a == b) cout << "C";
    else if (b == c) cout << "A";
    else cout << "B";

    return 0;
}