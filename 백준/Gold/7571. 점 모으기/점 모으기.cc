#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
vector<pii> v;
vector<int> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	v.resize(m);

	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
		x.push_back(v[i].first);
		y.push_back(v[i].second);
	}

	sort(all(x));
	sort(all(y));

	int px = x[x.size() / 2];
	int py = y[y.size() / 2];

	int res = 0;
	for (int i = 0; i < m; i++) {
		res += abs(px - v[i].first) + abs(py - v[i].second);
	}

	cout << res << "\n";


	

	return 0;
}