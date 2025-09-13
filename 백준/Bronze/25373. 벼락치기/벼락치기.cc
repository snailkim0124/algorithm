#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    if (n <= 1) cout << 1;
    else if (n <= 3) cout << 2;
    else if (n <= 6) cout << 3;
    else if (n <= 10) cout << 4;
    else if (n <= 15) cout << 5;
    else if (n <= 21) cout << 6;
    else if (n % 7 == 0) cout << (n / 7) + 3;
    else cout << (n / 7) + 4 << "\n";
    

    return 0;
}