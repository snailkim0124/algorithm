#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int n, m;
ll arr[100005];
ll pref[100005];
ll mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i - 1] + arr[i];
    }

    for (int i = 0; i < n - m; i++) {
        mx = max(mx, pref[i + m] - pref[i]);
    }

    cout << mx;

    
    return 0;
}