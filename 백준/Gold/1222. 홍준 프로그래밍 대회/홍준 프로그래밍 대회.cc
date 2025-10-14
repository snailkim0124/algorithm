#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll MAX = 2000005;
ll cnt[MAX];
ll n, mx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		cnt[num]++;
		mx = max(mx, num);
	}

	ll ans = n;
	for (ll i = 1; i <= mx; i++) {
		ll tmp = 0;
		for (ll j = 1; j * i <= mx; j++) {
			tmp += cnt[i * j];
		}

		if (tmp >= 2) ans = max(ans, i * tmp);
	}

	cout << ans << "\n";

	return 0;
}
