#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	int s, e;
	double v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
int parent[100005];
vector<pair<double, double>> v;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
double res;

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

	cin >> n;
	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double c = sqrt(pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2));
			pq.push({ i, j, c });
		}
	}

	int useEdge = 0;

	while (useEdge < n - 1) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << res;
	return 0;
}