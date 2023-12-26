#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct EDGE {
	ll s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

ll n, m, k;
ll parent[1005];
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq; // 오름차순
ll city[1005];
ll res = 0;

ll findParent(ll a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(ll a, ll b, ll c) {
	a = findParent(a);
	b = findParent(b);

	if (city[a] && city[b]) return; // 도시 둘다 있는 경우
	else if (city[a] && !city[b]) {
		parent[b] = a;
		res += c;
	}
	else {
		parent[a] = b;
		res += c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) { // 부모 초기화
		parent[i] = i;
	}

	for (int i = 0; i < k; i++) {
		ll num;
		cin >> num;
		city[num] = 1;
	}

	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		pq.push({ u,v,w });
	}

	ll useEdge = 0;

	while (!pq.empty()) {
		EDGE now = pq.top();
		pq.pop();

		if (findParent(now.s) != findParent(now.e)) { // 연결핻도 사이클이 생기지 않는다면
			unionParent(now.s, now.e, now.v);
			useEdge++;
		}
	}

	cout << res;
	return 0;
}