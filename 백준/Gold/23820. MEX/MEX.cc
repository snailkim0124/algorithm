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
ll a[2000005];
ll cnt[2000005];
vector<ll> v;
bool check[2000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
		cnt[a[i]]++;
	}

	if (!cnt[0]) {
		cout << 0 << "\n";
		exit(0);
	}

	if (!cnt[1]) {
		cout << 1 << "\n";
		exit(0);
	}

	sort(all(v));
	v.erase(unique(all(v)), v.end());

	for (ll x : v) {
		for (ll y : v) {
			ll tmp = x * y;
			if (tmp > 2000003) break;
			check[tmp] = 1;
		}
	}

	for (ll i = 2; i <= 2000003; i++) {
		if (!check[i]) {
			cout << i << "\n";
			break;
		}
	}

	

	return 0;
}