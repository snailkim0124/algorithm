#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
map<ll, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	if (n > m) {
		cout << -1 << "\n";
		exit(0);
	}

	vector<ll> ans;
	for (ll i = 1; i <= m; i++) {
		if (!mp[i]) {
			ans.push_back(i);
			mp[i ^ k]++;
		}

		if (ans.size() == n) break;
	}

	if (ans.size() < n) {
		cout << -1 << "\n";
		exit(0);
	}
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << "\n";
	
	
	return 0;
}