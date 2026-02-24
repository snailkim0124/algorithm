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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	ll target;
	if (n % 2 == 0) {
		target = (n / 2) * (n / 2);
	}
	else {
		target = (n / 2) * (n - n / 2);
	}

	if (target < k) {
		cout << "NO\n";
		exit(0);
	}

	cout << "YES\n";
	vector<pii> ans;
	for (int i = 1; i <= n / 2; i++) {
		for (int j = n / 2 + 1; j <= n; j++) {
			if (ans.size() == k) break;
			ans.push_back({ i, j });
		}
		if (ans.size() == k) break;
	}
	for (auto [u, v] : ans) {
		cout << u << " " << v << "\n";
	}
	
	return 0;
}