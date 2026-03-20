#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k;
vector<vector<int>> board;
int num = 1;

void go(int y, int x, int hy, int hx, int sz) {
	if (sz == 1) return;

	int nnum = num++;

	// 2사분면
	if (hy < y + sz / 2 && hx < x + sz / 2) {
		// 채워진 부분이 있는 경우
		go(y, x, hy, hx, sz / 2);
	}
	else {
		// 없는 경우 => 대각선에 구멍 새로 만들기
		board[y + sz / 2 - 1][x + sz / 2 - 1] = nnum;
		go(y, x, y + sz / 2 - 1, x + sz / 2 - 1, sz / 2);
	}

	// 1사분면
	if (hy < y + sz / 2 && hx >= x + sz / 2) {
		go(y, x + sz / 2, hy, hx, sz / 2);
	}
	else {
		board[y + sz / 2 - 1][x + sz / 2] = nnum;
		go(y, x + sz / 2, y + sz / 2 - 1, x + sz / 2, sz / 2);
	}

	// 3사분면
	if (hy >= y + sz / 2 && hx < x + sz / 2) {
		go(y + sz / 2, x, hy, hx, sz / 2);
	}
	else {
		board[y + sz / 2][x + sz / 2 - 1] = nnum;
		go(y + sz / 2, x, y + sz / 2, x + sz / 2 - 1, sz / 2);
	}

	// 4사분면
	if (hy >= y + sz / 2 && hx >= x + sz / 2) {
		go(y + sz / 2, x + sz / 2, hy, hx, sz / 2);
	}
	else {
		board[y + sz / 2][x + sz / 2] = nnum;
		go(y + sz / 2, x + sz / 2, y + sz / 2, x + sz / 2, sz / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int hy, hx;
	cin >> k;
	cin >> hx >> hy;

	int n = (1 << k);
	board.resize(n, vector<int>(n, 0));

	hy = n - hy;
	hx--;

	board[hy][hx] = -1;

	go(0, 0, hy, hx, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}