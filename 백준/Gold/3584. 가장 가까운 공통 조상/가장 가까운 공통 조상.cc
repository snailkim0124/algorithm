#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;
int parent[10005], visited[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		
		cin >> n;

		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a;
		}
		
		int a, b;
		cin >> a >> b;
		
		// lca
		while (a != parent[a]) {
			visited[a] = 1;
			a = parent[a];
		}

		while (b != parent[b]) {
			if (visited[b]) {
				cout << b << "\n";
				break;
			}
			b = parent[b];
		}
	}

	return 0;
}