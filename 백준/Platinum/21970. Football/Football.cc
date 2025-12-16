#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	while (k > 0) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}

		// 합이 홀수면 이김(처음에 1씩 가져가기)
		if (sum % 2 == 1) {
			cout << 1;
			return;
		}

		// 짝수면 모두 2씩 나눈 상태와 같음
		k >>= 1;
		for (int i = 0; i < n; i++) {
			a[i] >>= 1;
		}

		if (sum == 0) break;
	}

	cout << 0;
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