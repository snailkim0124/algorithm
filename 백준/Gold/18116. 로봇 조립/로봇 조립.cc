#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll parent[1000005];
ll dist[1000005];

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
		// 친구비 적은 곳
		if (dist[a] > dist[b]) swap(a, b);
		parent[b] = a;
		dist[a] += dist[b];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= 1000000; i++) {
		parent[i] = i;
		dist[i] = 1;
	}

	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'I') {
			ll a, b;
			cin >> a >> b;
			unionParent(a, b);
		}
		else if (cmd == 'Q') {
			ll a;
			cin >> a;
			cout << dist[findParent(a)] << "\n";
		}
	}

	return 0;
}