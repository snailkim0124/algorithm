#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll MAX = 1000000;
map<int, int> mp_arr[105];
map<int, int> mp;

vector<ll> sosu(int idx, ll n) {
	vector<ll> factor;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			factor.push_back(i);
			mp_arr[idx][i]++;
			n /= i;
		}
	}

	if (n > 1) {
		factor.push_back(n);
		mp_arr[idx][n]++;
	}

	return factor;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		vector<ll> res = sosu(i, v[i]);

		for (auto it : res) {
			// cout << it << " ";
			mp[it]++;
		}
		// cout << "\n";
	}

	ll res = 1;
	ll cnt = 0;

	for (auto it : mp) {
		if (it.second / n >= 1) {
			ll tmp = it.second / n;
			res *= pow(it.first, tmp);

			for (int i = 0; i < n; i++) {
				if (mp_arr[i][it.first] < tmp) {
					cnt += tmp - mp_arr[i][it.first];
				}
			}
		}
	}

	cout << res << " " << cnt << "\n";

	
	return 0;
}