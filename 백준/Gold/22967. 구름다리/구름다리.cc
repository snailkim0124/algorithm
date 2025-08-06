#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int dist[305][305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	if (n <= 4) {
		// K
		int k;
		if (n == 2) k = 0;
		else if (n == 3) k = 1;
		else if (n == 4) k = 3;
		cout << k << "\n";

		// R
		cout << 1 << "\n";

		// 구름다리
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (!dist[i][j]) {
					cout << i << " " << j << "\n";
					k--;
					if (!k) exit(0);
				}
			}
		}

	}
	else {
		// K
		int k = n - 2;
		cout << k << "\n";

		// R
		cout << 2 << "\n";

		// 구름다리
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (!dist[i][j]) {
					cout << i << " " << j << "\n";
					k--;
					if (!k) exit(0);
				}
			}
		}
	}

	return 0;
}