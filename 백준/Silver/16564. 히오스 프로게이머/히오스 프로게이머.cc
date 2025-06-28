#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k;
ll arr[1000005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	ll left = arr[0];
	ll right = arr[n - 1] + k;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < n; i++) {
			sum += max(0LL, mid - arr[i]);
		}

		if (k >= sum) {
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