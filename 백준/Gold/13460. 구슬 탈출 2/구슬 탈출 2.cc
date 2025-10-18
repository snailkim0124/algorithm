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
}MARBLE;

int n, m;
char arr[15][15];
MARBLE marble;

void printarr() {
	cout << "===========================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "===========================\n";
}

MARBLE moving(int dir, MARBLE now) {
	auto [ry, rx, by, bx, cnt] = now;

	if (dir == 0) { // 상
		if (ry > by) { // 빨간구슬이 더 아래
			// 파란구슬 먼저
			while (1) {
				int nby = by - 1;
				int nbx = bx;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}

			while (1) {
				int nry = ry - 1;
				int nrx = rx;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}
		}
		else { // 파란구슬이 더 아래
			// 빨간구슬 먼저
			while (1) {
				int nry = ry - 1;
				int nrx = rx;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}

			while (1) {
				int nby = by - 1;
				int nbx = bx;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}
		}
	}
	else if (dir == 1) { // 하
		if (ry > by) { // 빨간구슬이 더 아래
			// 빨간구슬 먼저

			while (1) {
				int nry = ry + 1;
				int nrx = rx;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}

			while (1) {
				int nby = by + 1;
				int nbx = bx;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}

		}
		else { // 파란구슬이 더 아래
			// 파란구슬 먼저
			while (1) {
				int nby = by + 1;
				int nbx = bx;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}

			while (1) {
				int nry = ry + 1;
				int nrx = rx;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}
		}
	}
	else if (dir == 2) { // 좌
		if (rx < bx) { // 빨간구슬이 왼쪽에 있음
			// 빨간구슬 먼저
			while (1) {
				int nry = ry;
				int nrx = rx - 1;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}

			while (1) {
				int nby = by;
				int nbx = bx - 1;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}
		}
		else {
			// 파란구슬 먼저
			while (1) {
				int nby = by;
				int nbx = bx - 1;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}

			while (1) {
				int nry = ry;
				int nrx = rx - 1;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}
		}
	}
	else if (dir == 3) { // 우
		if (rx < bx) { // 빨간구슬이 왼쪽에 있음
			// 파란구슬 먼저
			while (1) {
				int nby = by;
				int nbx = bx + 1;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}

			while (1) {
				int nry = ry;
				int nrx = rx + 1;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}
		}
		else {
			// 빨간구슬 먼저
			while (1) {
				int nry = ry;
				int nrx = rx + 1;

				if (arr[nry][nrx] == '.' && !(nry == by && nrx == bx)) {
					ry = nry;
					rx = nrx;
				}
				else if (arr[nry][nrx] == 'O') {
					ry = nry;
					rx = nrx;
					break;
				}
				else break;
			}

			while (1) {
				int nby = by;
				int nbx = bx + 1;

				if (arr[nby][nbx] == '.' && !(nby == ry && nbx == rx)) {
					by = nby;
					bx = nbx;
				}
				else if (arr[nby][nbx] == 'O') {
					by = nby;
					bx = nbx;
					break;
				}
				else break;
			}
		}
	}

	//if (arr[ry][rx] != 'O') {
	//	arr[ry][rx] = 'R';
	//}
	//if (arr[by][bx] != 'O') {
	//	arr[by][bx] = 'B';
	//}

	return { ry, rx, by, bx, cnt + 1 };
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

	//moving(3, marble);
	//printarr();

	queue<MARBLE> q;
	q.push(marble);
	while (!q.empty()) {
		MARBLE now = q.front();
		q.pop();

		if (now.cnt > 10) {
			break;
		}

		// 빨간 구슬 들어간 경우
		if (arr[now.ry][now.rx] == 'O') {
			cout << now.cnt << "\n";
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			MARBLE nm = moving(i, now);
			// 파란구슬이 먼저 들어간 경우
			if (arr[nm.by][nm.bx] == 'O') continue;
			q.push(nm);
		}
	}

	cout << -1 << "\n";


	return 0;
}