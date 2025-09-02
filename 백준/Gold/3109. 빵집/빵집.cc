#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c;
char arr[10005][505];
int visited[10005][505];
int cnt;
const int dy[3] = { -1,0,1 };
const int dx[3] = { 1,1,1 };

bool go(int y, int x) {
	visited[y][x] = 1;

	if (x == c - 1) {
		cnt++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
		if (arr[ny][nx] == 'x') continue;
		if (go(ny, nx)) return true;
	}

	return false;
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
		go(i, 0);
	}

	cout << cnt << "\n";
	

	return 0;
}