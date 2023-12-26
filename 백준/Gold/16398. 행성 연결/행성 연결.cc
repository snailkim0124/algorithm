#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	ll s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
ll parent[1005];
ll arr[1005][1005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순


int findParent(ll a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(ll a, ll b) {
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push({ i, j, arr[i][j] });
		}
	}

	ll useEdge = 0;
	ll res = 0;

	while (useEdge < n - 1) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결해도 사이클이 생기지 않는다면
			unionParent(now.s, now.e);
			res += now.v;
			useEdge++;
		}
	}

	cout << res;

	return 0;
}