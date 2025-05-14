#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll x, k;
ll cntL[10005], cntR[10005];
ll res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> k;
    for (int i = 0; i < x; i++) {
        ll num;
        cin >> num;
        cntL[num]++;
    }

    for (int i = 0; i < x; i++) {
        ll num;
        cin >> num;
        cntR[num]++;
    }

    for (int i = 1; i <= k; i++) {
        res += cntL[i] * cntR[i];
    }

    cout << x * x - res;
    
    return 0;
}