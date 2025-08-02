#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int w[15][15]; // i -> j
int visited[15];
int mn = 987654321;

void go(int start, int now, int depth, int val) {
	if (depth == n - 1) {
		// 마지막은 다시 돌아와야 됨
		if (w[now][start] != 0) {
			mn = min(mn, val + w[now][start]);
		}

		return;
	}

	for (int i = 0; i < n; i++) {
		if (w[now][i] != 0 && !visited[i]) {
			visited[i] = 1;
			go(start, i, depth + 1, val + w[now][i]);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (w[i][j] != 0) {
				memset(visited, 0, sizeof(visited));
				visited[i] = 1;
				visited[j] = 1;
				go(i, j, 1, w[i][j]);
			}
		}
	}
	
	cout << mn;

	return 0;
}