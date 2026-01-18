#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k, d;
vector<tll> v;

bool check(ll mid) {
	ll cnt = 0;
	// 규칙 순회
	for (auto [a, b, c] : v) {
		if (mid < a) continue;
		cnt += (min(b, mid) - a) / c + 1;
	}

	return cnt >= d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k >> d;
	for (int i = 0; i < k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	ll left = 1;
	ll right = n;
	ll res = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << res << "\n";

	return 0;
}