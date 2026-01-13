#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<tii> v;
map<tii, int> mp;
int parent[3005];

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	v.resize(n + 1);
	// 좌표 압축
	for (int i = 1; i <= n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		mp[{x, y, r}] = i;
		v[i] = { x, y, r };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			auto [x1, y1, r1] = v[i];
			auto [x2, y2, r2] = v[j];

			// 상호 간 통신가능
			if (dist(x1, y1, x2, y2) <= (r1 + r2) * (r1 + r2)) {
				unionParent(mp[v[i]], mp[v[j]]);
			}
		}
	}

	
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(findParent(mp[v[i]]));
	}

	//cout << "ans : ";
	cout << s.size() << "\n";

	mp.clear();
	memset(parent, 0, sizeof(parent));
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