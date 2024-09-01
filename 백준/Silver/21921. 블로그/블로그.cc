#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x, n;
ll arr[250005];
ll pref[250005];
ll mx, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pref[i] = pref[i - 1] + arr[i];
	}

	for (int i = x; i <= n; i++) {
		mx = max(mx, pref[i] - pref[i - x]);
	}

	for (int i = x; i <= n; i++) {
		if (mx == pref[i] - pref[i - x]) cnt++;
	}

	if (!mx) cout << "SAD";
	else cout << mx << "\n" << cnt;

	return 0;
}