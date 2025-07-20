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

void go(int depth, int cnt) {
	if (depth == cnt) {
		if (check()) {
			cout << cnt;
			exit(0);
		}
		return;
	}


	for (int j = 1; j < n; j++) {
		for (int i = 1; i <= h; i++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go(depth, cnt + 1);
			visited[i][j] = 0;

			while (!visited[i][j - 1] && !visited[i][j + 1]) i++; // 불필요한 연산 넘기기
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

	// 최대값이 3밖에 안되기에 가능함
	for (int i = 0; i <= 3; i++) {
		go(i, 0);
	}
	
	cout << -1;

	return 0;
}