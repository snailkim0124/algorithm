#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct MARBLE {
	int ry, rx, by, bx, cnt;
	string memo;
}MARBLE;

int n, m;
char arr[15][15];
int visited[15][15][15][15];
MARBLE marble;
const int dy[4] = { -1,1,0,0 }; // 상하좌우
const int dx[4] = { 0,0,-1,1 };
string cmd = "UDLR";

pii moving(int y, int x, int dir) {
	while (1) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (arr[ny][nx] == '#') break;
		y = ny; x = nx;
		if (arr[ny][nx] == 'O') break;
	}

	return { y, x };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				marble.ry = i;
				marble.rx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				marble.by = i;
				marble.bx = j;
				arr[i][j] = '.';
			}
		}
	}

	marble.cnt = 0;

	queue<MARBLE> q;
	q.push(marble);
	visited[marble.ry][marble.rx][marble.by][marble.bx] = 1;

	while (!q.empty()) {
		auto [ry, rx, by, bx, cnt, memo] = q.front();
		q.pop();

		if (cnt >= 10) continue;

		for (int i = 0; i < 4; i++) {
			int nry = ry, nrx = rx, nby = by, nbx = bx;

			bool flag = false;
			if (i == 0 && ry < by) flag = true;
			else if (i == 1 && ry > by) flag = true;
			else if (i == 2 && rx < bx) flag = true;
			else if (i == 3 && rx > bx) flag = true;

			// 빨간구슬 먼저
			if (flag) {
				tie(nry, nrx) = moving(ry, rx, i);
				tie(nby, nbx) = moving(by, bx, i);
			}
			else {
				tie(nby, nbx) = moving(by, bx, i);
				tie(nry, nrx) = moving(ry, rx, i);

			}

			// 파란 구슬 빠짐
			if (arr[nby][nbx] == 'O') continue;

			// 빨간 구슬 빠짐
			if (arr[nry][nrx] == 'O') {
				cout << cnt + 1 << "\n";
				cout << memo + cmd[i] << "\n";
				exit(0);
			}

			// 같은 칸일때 뒤로 한칸
			if (nry == nby && nrx == nbx) {
				int rd = abs(nry - ry) + abs(nrx - rx);
				int bd = abs(nby - by) + abs(nbx - bx);
				if (rd > bd) {
					nry -= dy[i];
					nrx -= dx[i];
				}
				else {
					nby -= dy[i];
					nbx -= dx[i];
				}
			}

			if (!visited[nry][nrx][nby][nbx]) {
				visited[nry][nrx][nby][nbx] = 1;
				q.push({ nry, nrx, nby, nbx, cnt + 1, memo + cmd[i]});
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}