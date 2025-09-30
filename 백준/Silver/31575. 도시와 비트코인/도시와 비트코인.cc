#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int arr[305][305];
int visited[305][305];
const int dy[2] = { 0,1 };
const int dx[2] = { 1,0 };

void bfs() {
	queue<pii> q;
	visited[0][0] = 1;
	q.push({ 0 ,0 });

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
			if (arr[ny][nx] == 1) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	bfs();

	cout << (visited[m - 1][n - 1] ? "Yes" : "No");
	
	return 0;
}