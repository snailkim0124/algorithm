#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int h, w, r, c, d;
char a[70][70], b[70][70];
const int dy[4] = { -1,0,1,0 }; // 상,우,하,좌
const int dx[4] = { 0,1,0,-1 }; 
int munji[70][70], visited[70][70][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	cin >> r >> c >> d;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			munji[i][j] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b[i][j];
		}
	}

	int ans = 0;
	int cnt = 0;
	int idx = 1;

	while (1) {
		if (r < 0 || c < 0 || r >= h || c >= w) break;

		// 먼지가 있음
		if (munji[r][c]) {
			ans = cnt;

			munji[r][c] = 0;

			idx++;

			int nd = a[r][c] - '0';
			d = (d + nd) % 4;
		}
		// 먼지가 없음
		else {
			if (visited[r][c][d] == idx) break;
			visited[r][c][d] = idx;

			int nd = b[r][c] - '0';
			d = (d + nd) % 4;
		}

		// 이동
		r += dy[d];
		c += dx[d];
		cnt++;
	}

	cout << ans + 1 << "\n";
	

	return 0;
}