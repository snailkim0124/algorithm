#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
ll arr[10005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
	}

	if (n <= m) {
		cout << n;
		exit(0);
	}

	ll left = 0;
	ll right = 30 * n; // 최대 30분까지 가능

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = m;
		for (int i = 1; i <= m; i++) {
			sum += mid / arr[i];
		}

		if (sum >= n) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	// cout << "res : " << res << "\n";

	ll cnt = 0;
	for (int i = 1; i <= m; i++) {
		cnt += (res - 1) / arr[i] + 1;
	}

	for (int i = 1; i <= m; i++) {
		if (res % arr[i] == 0) cnt++;
		if (cnt == n) {
			cout << i;
			break;
		}
	}

	return 0;
}