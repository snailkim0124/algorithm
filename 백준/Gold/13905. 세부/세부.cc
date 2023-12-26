#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v < temp.v;
	}
}EDGE;

int n, m;
int S, E;
int parent[100005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
const int INF = 987654321;
int visited[100005];
vector<pair<int, int>> v[100005];

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

	if (a < b) {
		parent[b] = a;
	}
	else parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> S >> E;
	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			v[now.s].push_back({ now.e, now.v });
			v[now.e].push_back({ now.s, now.v });
		}
	}

	fill(visited, visited + 100005, INF);

	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		for (auto there : v[here]) {
			int next = there.first;
			int nw = there.second;
			if (visited[next] != INF) continue; // 방문한 경우

			visited[next] = min(nw, visited[here]);
			q.push(next);
		}
	}

	if (visited[E] == INF) cout << 0;
	else cout << visited[E];

	return 0;
}