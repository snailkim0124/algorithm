#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[505][505];
int visited[505][505];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = -1;

int go(int y, int x) {
	if (visited[y][x]) return visited[y][x];

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (arr[y][x] < arr[ny][nx]) {
			visited[y][x] = max(visited[y][x], go(ny, nx) + 1);
		}
	}

	return visited[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, go(i, j));
		}
	}

	cout << res;

	return 0;
}