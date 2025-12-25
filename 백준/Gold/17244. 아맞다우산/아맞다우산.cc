#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct NEED {
	int y, x, bit, cnt;
};

const int INF = 987654321;
int n, m;
char arr[55][55];
int visited[55][55][1 << 5];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int sy, sx, ey, ex;
vector<pii> needs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sy = i; sx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'E') {
				ey = i; ex = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'X') {
				needs.push_back({ i, j });
				arr[i][j] = '.';
			}
		}
	}

	queue<NEED> q;
	q.push({ sy, sx, 0, 0 });
	visited[sy][sx][0] = 1;

	int cnt = 0;
	while (!q.empty()) {
		auto [y, x, bit, cnt] = q.front();
		q.pop();

		if (y == ey && x == ex && bit == (1 << needs.size()) - 1) {
			cout << cnt << "\n";
			exit(0);
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];


			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == '#') continue; // 밖으로 나갈일 없음

			int nb = bit;
			for (int j = 0; j < needs.size(); j++) {
				if (needs[j].first == ny && needs[j].second == nx) {
					nb |= (1 << j);
					break;
				}
			}

			if (!visited[ny][nx][nb]) {
				visited[ny][nx][nb] = 1;
				q.push({ ny, nx, nb, cnt + 1 });
			}
		}

	}

	return 0;
}