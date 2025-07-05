#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[105][105];
int visited[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int cnt;

int bfs() {
	bool isMelted = false;
	queue<pii> q;
	visited[0][0] = 1;
	q.push({ 0 ,0 });

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 1) {
				visited[ny][nx]++;
				if (visited[ny][nx] >= 2) {
					arr[ny][nx] = 0;
				}
				isMelted = true;
			}
			else if(arr[ny][nx] == 0 && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}

	return isMelted;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		if (!bfs()) break;
		cnt++;
	}

	cout << cnt;

	return 0;
}