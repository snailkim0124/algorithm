#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
int deg[100005];
vector<int> adj[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[y].push_back(x);
	}

	while (k--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			for (auto it : adj[b]) {
				if (deg[it] == 0) {
					cout << "Lier!\n";
					exit(0);
				}
			}
			deg[b]++;
		}
		else if (a == 2) {
			if (deg[b] == 0) {
				cout << "Lier!\n";
				exit(0);
			}
			deg[b]--;
		}
	}
	
	cout << "King-God-Emperor\n";
	
	return 0;
}