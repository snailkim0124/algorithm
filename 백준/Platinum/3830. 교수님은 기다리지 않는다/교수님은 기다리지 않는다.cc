#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int parent[100005];
int dist[100005];

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		// 가중치 더하기
		int root = findParent(parent[a]);
		dist[a] += dist[parent[a]];
		return parent[a] = root;
	}
}

void unionParent(int a, int b, int w) {
	int parenta = findParent(a);
	int parentb = findParent(b);

	if (parenta != parentb) {
		dist[parentb] = dist[a] - dist[b] + w;
		parent[parentb] = parenta;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		memset(parent, 0, sizeof(parent));
		memset(dist, 0, sizeof(dist));

		int n, m;
		cin >> n >> m;
		if (!n && !m) break;

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		while (m--) {
			int a, b, w;
			char c;
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				unionParent(a, b, w);

			}
			else if (c == '?') {
				cin >> a >> b;
				if (findParent(a) == findParent(b)) {
					cout << dist[b] - dist[a] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}


	
	return 0;
}