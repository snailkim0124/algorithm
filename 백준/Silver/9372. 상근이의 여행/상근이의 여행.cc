#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << n - 1 << "\n"; // 간선의 개수 = 노드 개수 -1
	}
	return 0;
}