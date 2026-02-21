#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct EDGE {
	int s, e;
	double v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n;
int parent[1000005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순

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

double dist(pll a, pll b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<pll> v(n + 1);
	for (int i = 1; i <= n; i++) {
		ll x, y;
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push({ i, j, dist(v[i], v[j]) });
		}
	}

	int useEdge = 0;
	double res = 0;

	while (useEdge < n - 1) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	cout << res << "\n";
	
	pq = priority_queue<EDGE, vector<EDGE>, greater<EDGE>>();
	memset(parent, 0, sizeof(parent));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(2);

	while (1) {
		cin >> n;
		if (!n) break;
		solve();
	}


	return 0;
}