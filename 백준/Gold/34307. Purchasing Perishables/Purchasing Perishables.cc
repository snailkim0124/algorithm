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
ll p[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	ll mn = LLONG_MAX;
	for (ll k = 1; k <= n; k++) {
		ll sum = 0;
		for (ll i = 1; i <= n; i += k) {
			sum += p[i] * min(k, n - i + 1); // 끝인 경우
		}

		mn = min(mn, sum);
	}

	cout << mn << "\n";

	return 0;
}