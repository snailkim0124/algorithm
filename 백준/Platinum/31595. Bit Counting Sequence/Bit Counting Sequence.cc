#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll count_one(ll n) {
	ll cnt = 0;
	while (n > 0) {
		n = n & (n - 1); 
		cnt++;
	}
	return cnt;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	ll res = 0;
	ll mx = 0;

	for (int i = 0; i < n - 1; i++) {
		ll diff = a[i + 1] - a[i];
		ll p = 1 - diff;

		if (p < 0) {
			cout << -1 << "\n";
			return;
		}

		// 오버플로우 방지
		ll tmp = (1LL << (p + 1)) - 1;
		ll val = ((1LL << p) - 1 - i) & tmp; // 2^p - i

		// 이전 거와 비교 했을때 같으면 안됨
		ll cmx = min(mx, p + 1);
		ll ctmp = (1LL << cmx) - 1;

		if ((res & ctmp) != (val & ctmp)) {
			cout << -1 << "\n";
			return;
		}

		if (mx < p + 1) {
			mx = p + 1;
			res = val;
		}
	}

	ll cnt = count_one(res);
	ll need = a[0] - cnt;

	if (need < 0) {
		cout << -1 << "\n";
		return;
	}

	// 비트 채우기
	for (int i = 0; i < need; i++) {
		res |= (1LL << (mx + i));
	}
	
	//cout << "ans : ";
	cout << res << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}