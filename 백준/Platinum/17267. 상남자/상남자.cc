#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct MOVE {
	int y, x, l, r;
}MOVE;

int n, m, l, r;
char arr[1005][1005];
int sy, sx;
int visited[1005][1005];
const int dy[4] = { -1,1,0,0 };// 상하우좌
const int dx[4] = { 0,0,1,-1 };

void printarr() {
	cout << "============================\n";
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
			if (visited[i][j]) cnt++;
		}
		cout << "\n";
	}

	cout << "cnt : " << cnt << "\n";

	cout << "============================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '2') {
				sy = i; sx = j;
			}
		}
	}

	queue<MOVE> q;
	q.push({ sy, sx, l, r });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		auto [y, x, l, r] = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int ny = y;
			int nx = x;

			while (ny >= 0 && ny < n) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
				if (arr[ny][nx] == '1') break;
				else {
					visited[ny][nx] = 1;
					q.push({ ny, nx, l, r });
				}
			}
		}

		for (int i = 2; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || arr[ny][nx] == '1') continue;
			if (i == 2 && r != 0) {
				visited[ny][nx] = 1;
				q.push({ ny, nx, l, r - 1 });
			}
			else if(i == 3 && l != 0) {
				visited[ny][nx] = 1;
				q.push({ ny, nx, l - 1, r });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}