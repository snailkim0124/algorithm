#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
int parent[100005];
vector<pair<int, int>> x, y, z;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
int res;

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
		int X, Y, Z;
		cin >> X >> Y >> Z;
		x.push_back({ X, i });
		y.push_back({ Y, i });
		z.push_back({ Z, i });
	}

	// 정렬로 공간 복잡도 낮추기
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < n - 1; i++) {
		pq.push({ x[i].second, x[i + 1].second ,abs(x[i + 1].first - x[i].first) });
		pq.push({ y[i].second, y[i + 1].second ,abs(y[i + 1].first - y[i].first) });
		pq.push({ z[i].second, z[i + 1].second ,abs(z[i + 1].first - z[i].first) });

	}

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
		}
	}
	cout << res;
	return 0;
}