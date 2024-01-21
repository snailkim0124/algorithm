#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t;
ll n, m, k;
ll parent[20005];
ll dist[20005];

ll findParent(ll a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		// 거리 추가(병합 과정)
		ll idx = findParent(parent[a]);
		dist[a] += dist[parent[a]];
		return parent[a] = idx;
	}
}

void unionParent(ll a, ll b) {
	// 통신라인 연결(b에 의해 제공)
	dist[a] = abs(b - a) % 1000;
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(parent, 0, sizeof(parent));
		memset(dist, 0, sizeof(dist));
		ll n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		while (1) {
			char cmd;
			cin >> cmd;
			if (cmd == 'O') break;
			else if (cmd == 'E') {
				ll a;
				cin >> a;
				findParent(a);
				cout << dist[a] << "\n";
			}
			else if (cmd == 'I') {
				ll a, b;
				cin >> a >> b;
				unionParent(a, b);
			}
		}

	}

	return 0;
}