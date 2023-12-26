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
int parent[1005];
char school[1005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순


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
		cin >> school[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if (school[u] != school[v]) { // 남여 성별이 다를때 연결
			pq.push({ u,v,d });
		}
	}

	int useEdge = 0;
	int res = 0;

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	if (useEdge == n - 1) {
		cout << res;
	}
	else cout << -1;

	return 0;
}