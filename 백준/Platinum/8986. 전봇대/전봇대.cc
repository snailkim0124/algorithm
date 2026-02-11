#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll tmp[100005], arr[100005];

ll f(ll diff) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(diff * i - arr[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll left = 0;
	ll right = arr[n - 1];

	// 삼분 탐색 (최솟값 찾기)
	while (right - left >= 3) {
		ll p1 = (left * 2 + right) / 3;
		ll p2 = (left + right * 2) / 3;

		if (f(p1) <= f(p2)) right = p2;
		else left = p1;
	}

	ll res = LLONG_MAX;
	//cout << left << " : " << right << "\n";

	for (int i = left; i <= right; i++) {
		res = min(res, f(i));
	}

	cout << res << "\n";

	return 0;
}