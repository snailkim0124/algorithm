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

	while (1) {
		priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
		memset(parent, 0, sizeof(parent));
		int sum = 0;
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		for (int i = 1; i <= m; i++) { // 부모 초기화
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			pq.push({ x,y,z });
			sum += z;
		}

		int res = 0;

		while (!pq.empty()) {
			EDGE now = pq.top();
			pq.pop();

			if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
				unionParent(now.s, now.e);
				res += now.v;
			}
		}

		cout << sum - res << "\n";
	}
	
	return 0;
}