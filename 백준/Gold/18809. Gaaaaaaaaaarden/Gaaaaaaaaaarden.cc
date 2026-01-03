#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, g, r;
int arr[55][55];
int visited[55][55];
int color[55][55]; // 3 : 초록, 4 : 빨강, 5 : 꽃
vector<pii> cul;
int res = 0;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

// 0 : 호수, 1 : 배양액 X, 2 : 배양액 o(안뿌림), 3 : 초록, 4 : 빨강
int bfs(vector<int> gr) {
	memset(visited, -1, sizeof(visited));
	memset(color, 0, sizeof(color));
	queue<pii> q;

	// 배양액 뿌리기
	for (int i = 0; i < cul.size(); i++) {
		if (gr[i] == 2) continue;

		auto [y, x] = cul[i];

		visited[y][x] = 0;
		color[y][x] = gr[i];
		q.push({ y, x });
	}

	int cnt = 0;
	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		// 꽃인 경우
		if (color[y][x] == 5) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 0) continue;
			
			// 아직 안뿌린 경우
			if (!color[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				color[ny][nx] = color[y][x];
				q.push({ ny, nx });
			}
			// 꽃이 아닌 경우
			else if (color[ny][nx] != 5) {
				if (color[ny][nx] != color[y][x] && visited[ny][nx] == visited[y][x] + 1) {
					color[ny][nx] = 5;
					cnt++;
				}
			}


		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				cul.push_back({ i, j });
			}
		}
	}

	// 후보
	vector<int> gr(cul.size());
	fill(all(gr), 2);

	for (int i = 0; i < g; i++) {
		gr[i] = 3;
	}
	for (int i = g; i < g + r; i++) {
		gr[i] = 4;
	}
	sort(all(gr));

	do {
		res = max(res, bfs(gr));

	} while (next_permutation(all(gr)));

	cout << res << "\n";


	return 0;
}