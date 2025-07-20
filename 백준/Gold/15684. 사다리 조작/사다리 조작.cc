#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, h;
int visited[35][10];
int res = 987654321;

bool check() {
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][now]) now++;
			else if (visited[j][now - 1]) now--;
		}

		if (now != i) return false;
	}

	return true;
}

void go(int a, int cnt) {
	if (cnt > 3) return;
	if (check()) {
		res = min(res, cnt);
		return;
	}

	for (int i = a; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}

	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}

	go(1, 0);

	if (res == 987654321) cout << -1;
	else cout << res;

	return 0;
}