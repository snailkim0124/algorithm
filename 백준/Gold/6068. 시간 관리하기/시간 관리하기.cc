#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<pll> v; // 끝내야, 필요한

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}

	sort(all(v), greater<>());

	//for (auto [a, b] : v) {
	//	cout << a << " " << b << "\n";
	//}

	int t = v[0].first;
	for (auto it : v) {
		if (t < it.first) t -= it.second;
		else {
			t = it.first - it.second;
			if (t < 0) {
				cout << -1 << "\n";
				exit(0);
			}
		}
	}

	cout << t << "\n";

	return 0;
}