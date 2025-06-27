#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k;
ll arr[10005];
ll mx = -1;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}

	ll left = 1;
	ll right = mx;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i] / mid;
		}

		if (sum >= k) {
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << res;
	
	return 0;
}