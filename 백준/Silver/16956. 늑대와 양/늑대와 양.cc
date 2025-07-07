#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int r, c;
char arr[505][505];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
bool res = true;

bool check(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (arr[ny][nx] == 'S') return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'W') {
				if (!check(i, j)) {
					res = false;
					break;
				}
			}
		}
		if (!res) break;
	}

	if (res) {
		cout << 1 << "\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == '.') cout << "D";
				else cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	else cout << 0;

	
	return 0;
}