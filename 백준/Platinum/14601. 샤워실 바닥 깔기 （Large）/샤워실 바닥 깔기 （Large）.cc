#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<vector<int>> board;
int num = 1;

bool check(int y, int x, int sz) {
	// 채워진 부분이 있는지 체크
	for (int i = y; i < y + sz; i++) {
		for (int j = x; j < x + sz; j++) {
			if (board[i][j] != 0) return true;
		}
	}
	return false;
}

void go(int y, int x, int sz) {
	if (sz == 1) return;

	int nnum = num++;
	int m = sz / 2;
	if (!check(y, x, m)) board[y + m - 1][x + m - 1] = nnum;
	if (!check(y + m, x, m)) board[y + m][x + m - 1] = nnum;
	if (!check(y, x + m, m)) board[y + m - 1][x + m] = nnum;
	if (!check(y + m, x + m, m)) board[y + m][x + m] = nnum;

	go(y, x, m); // 2사분면
	go(y, x + m, m); // 1사분면
	go(y + m, x, m); // 3사분면
	go(y + m, x + m, m); // 4사분면
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k, hy, hx;
	cin >> k >> hx >> hy;
	int n = (1 << k);
	board.resize(n, vector<int>(n, 0));

	hy = n - hy;
	hx--;
	board[hy][hx] = -1;

	go(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}