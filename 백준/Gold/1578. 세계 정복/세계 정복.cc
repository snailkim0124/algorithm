#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
ll arr[55];

bool check(ll mid) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(arr[i], mid);
	}

	return sum >= mid * k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + n, greater<>());

	ll left = 0;
	ll right = sum / k;
	ll res = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;

		if (check(mid)) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << res << "\n";

	return 0;
}