#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
ll arr[100005];
ll mn = INT_MAX;
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
	ll right = arr[0] * m; // 제일 최소인 경우

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / arr[i];
		}

		if (sum >= m) {
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