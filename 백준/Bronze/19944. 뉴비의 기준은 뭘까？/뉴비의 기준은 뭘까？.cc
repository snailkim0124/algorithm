#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    if (m == 1 || m == 2) cout << "NEWBIE!";
    else if (n >= m) cout << "OLDBIE!";
    else cout << "TLE!";

    return 0;
}