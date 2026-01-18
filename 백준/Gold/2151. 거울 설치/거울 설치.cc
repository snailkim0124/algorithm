#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct MIRROR {
	int cnt, y, x, dir;

	bool operator >(const MIRROR& tmp) const {
		return cnt > tmp.cnt;
	}

};

const int INF = 987654321;
int n;
char arr[55][55];
int sy = -1, sx = -1, ey = -1, ex = -1;
priority_queue<MIRROR, vector<MIRROR>, greater<MIRROR>> pq;
int dist[55][55][4];
const int dy[4] = { -1,1,0,0 }; // 상하좌우
const int dx[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (sy == -1 && sx == -1 && arr[i][j] == '#') {
				sy = i;
				sx = j;
			}
			else if (ey == -1 && ex == -1 && arr[i][j] == '#') {
				ey = i;
				ex = j;
			}
		}
	}

	fill(&dist[0][0][0], &dist[0][0][0] + 55 * 55 * 4, INF);

	for (int i = 0; i < 4; i++) {
		pq.push({ 0, sy, sx, i });
		dist[sy][sx][i] = 0;
	}

	while (!pq.empty()) {
		auto [cnt, y, x, dir] = pq.top();
		pq.pop();

		if (dist[y][x][dir] < cnt) continue;

		if (y == ey && x == ex) {
			cout << cnt << "\n";
			break;
		}

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] == '*') continue;
		if (dist[ny][nx][dir] > cnt) {
			dist[ny][nx][dir] = cnt;
			pq.push({ cnt, ny, nx, dir });
		}

		// 거울 설치
		if (arr[ny][nx] == '!') {
			vector<int> v;
			if (dir < 2) {
				v.push_back(2);
				v.push_back(3);
			}
			else {
				v.push_back(0);
				v.push_back(1);
			}

			for (int i = 0; i < 2; i++) {
				int ndir = v[i];
				if (dist[ny][nx][ndir] > cnt + 1) {
					dist[ny][nx][ndir] = cnt + 1;
					pq.push({ cnt + 1, ny, nx, ndir });
				}

			}
		}

	}
	



	
	return 0;
}