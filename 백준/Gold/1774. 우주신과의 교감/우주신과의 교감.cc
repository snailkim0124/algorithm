#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct EDGE {
	int s, e;
	double v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
int parent[1005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
pii v[1005];

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (findParent(x) != findParent(y)) unionParent(x, y);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double c = sqrt(pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2));
			pq.push({ i, j, c });
		}
	}

	double res = 0;

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << res;

	return 0;
}