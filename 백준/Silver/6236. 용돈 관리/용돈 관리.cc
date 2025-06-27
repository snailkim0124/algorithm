#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
ll arr[100005];
ll sum, mx = -1;
ll res = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		mx = max(mx, arr[i]);
	}

	ll left = mx; // 최소 인출 금액
	ll right = sum; // 최대 인출 금액

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll tmp = mid;
		ll cnt = 1;

		for (int i = 0; i < n; i++) {
			if (tmp < arr[i]) {
				cnt++;
				tmp = mid;
			}

			tmp -= arr[i];
		}

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			res = min(res, mid);
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}