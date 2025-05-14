#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if (n == 1) {
        for (int i = 0; i < k ; i++) {
            cout << 1 << " ";
        }
    }
    else {
        if (n == 2 && k == 1) cout << "1 2";
        else cout << -1;
    }

    
    return 0;
}