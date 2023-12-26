#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m, k;
int parent[55];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
vector<int> v;
int sum;

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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w = 0;
			char num;
			cin >> num;
			
			// 가중치 설정
			if (isupper(num)) {
				w = num - 'A' + 27;
			}
			else if (islower(num)) {
				w = num - 'a' + 1;
			}
			if (w == 0) continue;
			pq.push({ i, j, w });
			sum += w;
		}
	}


	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({ u,v,w });
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

	if (useEdge == n - 1) { // 다 사용한 경우
		cout << sum - res;
	}
	else cout << -1;
	return 0;
}