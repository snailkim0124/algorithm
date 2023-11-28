#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct LIST {
	int s, e, v;
	bool operator > (const LIST& temp) const {
		return v > temp.v;
	}
}LIST;

int n, m;
int parent[100005];
priority_queue<LIST, vector<LIST>, greater<LIST>> pq; // 오름차순


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

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	int useEdge = 0;
	int res = 0;

	while (useEdge < n - 1) {
		LIST now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	cout << res;
	return 0;
}