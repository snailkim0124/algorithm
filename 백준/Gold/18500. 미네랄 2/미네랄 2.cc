#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int r, c;
char arr[105][105];
int visited[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void bfs(int _y, int _x, int num) {
	queue<pii> q;
	q.push({ _y, _x });
	visited[_y][_x] = num;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (arr[ny][nx] == 'x' && !visited[ny][nx]) {
				visited[ny][nx] = num;
				q.push({ ny, nx });
			}
		}
	}
}


void falling() {
	memset(visited, 0, sizeof(visited));
	int num = 1;
	// 번호 매기기
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'x' && !visited[i][j]) {
				bfs(i, j, num);
				num++;
			}
		}
	}

	// 바닥에 붙어있는지 확인
	set<int> s;
	for (int j = 0; j < c; j++) {
		if (arr[r - 1][j] == 'x') s.insert(visited[r - 1][j]);
	}

	//for (auto it : s) {
	//	cout << it << " ";
	//}
	//cout << "\n";

	// 공중에 떠있는 클러스터 (1개)
	int idx = -1;
	for (int i = 1; i < num; i++) {
		if (!s.count(i)) {
			idx = i;
			break;
		}
	}

	if (idx == -1) return;

	// 클러스터 좌표
	vector<pii> v;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == idx) {
				v.push_back({ i, j });
				arr[i][j] = '.';
			}
		}
	}

	// 떨어뜨릴 높이
	int cnt = 0;
	while (1) {
		bool flag = false;
		for (auto [y, x] : v) {
			int ny = y + cnt + 1;
			int nx = x;

			if (ny >= r || arr[ny][nx] == 'x') {
				flag = true;
				break;
			}
		}

		if (flag) break;
		cnt++;
	}

	// 떨어뜨리기
	for (auto [y, x] : v) {
		arr[y + cnt][x] = 'x';
	}
}

void cave_left(int h) {
	for (int j = 0; j < c; j++) {
		if (arr[h][j] == 'x') {
			arr[h][j] = '.';
			break;
		}
	}

	falling();
}

void cave_right(int h) {
	for (int j = c - 1; j >= 0; j--) {
		if (arr[h][j] == 'x') {
			arr[h][j] = '.';
			break;
		}
	}

	falling();
}

void cave_print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
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

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int h;
		cin >> h;
		h = r - h;
		// 왼 -> 오
		if (i % 2 == 0) {
			cave_left(h);
		}
		// 오 -> 왼
		else {
			cave_right(h);
		}
		//cave_print();
	}

	cave_print();

	return 0;
}