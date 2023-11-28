#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t;
ll arr[1000005];
ll n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		ll res = 0;
		ll mx = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = n - 1; i >= 0; i--) {
			mx = max(mx, arr[i]);
			res += mx - arr[i];
		}

		cout << res << "\n";
	}

	return 0;
}