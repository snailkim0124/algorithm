#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = LLONG_MAX;
ll n, m;
char arr[3005][3005];
ll visited[3005][3005];
ll jy, jx, scy, scx;
vector<pii> teacher;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<ll> jtot, stot;

void bfs(int sy, int sx) {
	fill(&visited[0][0], &visited[0][0] + 3005 * 3005, INF);
	
	queue<pii> q;
	visited[sy][sx] = 0;
	q.push({ sy, sx });

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == '#') continue;
			if (visited[ny][nx] > visited[y][x] + 1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
		
	}
}

void printarr() {
	cout << "=======================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "=======================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') {
				teacher.push_back({ i, j });
			}
			else if (arr[i][j] == 'S') {
				scy = i;
				scx = j;
			}
			else if (arr[i][j] == 'J') {
				jy = i;
				jx = j;
			}
		}
	}

	jtot.assign(teacher.size(), INF);
	stot.assign(teacher.size(), INF);

	bfs(jy, jx);

	ll ans = INF;
	// 진우 - 승찬
	if (visited[scy][scx] != INF) {
		ans = min(ans, visited[scy][scx] * 2);
	}

	//printarr();

	// 진우 - 선생님
	for (int i = 0; i < teacher.size(); i++) {
		if (visited[teacher[i].first][teacher[i].second] != INF) {
			jtot[i] = visited[teacher[i].first][teacher[i].second] * 2;
		}
	}

	bfs(scy, scx);

	//printarr();
	
	// 선생님 - 승찬
	for (int i = 0; i < teacher.size(); i++) {
		if (visited[teacher[i].first][teacher[i].second] != INF) {
			stot[i] = visited[teacher[i].first][teacher[i].second];
		}
	}

	for (int i = 0; i < teacher.size(); i++) {
		if (jtot[i] != INF && stot[i] != INF) {
			ans = min(ans, jtot[i] + stot[i]);
		}
	}

	cout << (ans == INF ? -1 : ans) << "\n";

	return 0;
}