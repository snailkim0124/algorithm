#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
ll arr[1000005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	ll left = 1;
	ll right = arr[n - 1] * m;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / arr[i];
		}

		if (cnt >= m) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << res;
	

	return 0;
}