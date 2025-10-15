#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct EDGE {
	int s, e, v;
	bool operator > (const EDGE& temp) const {
		return v > temp.v;
	}
}EDGE;

int n, m;
char arr[55][55];
int sy, sx;
int visited[55][55];
int parent[255];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pii> key;
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;
map<pii, int> mp;
int res;

int findParent(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) parent[b] = a;
}

void printarr() {
	cout << "============================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "============================\n";
}

void bfs(int _y, int _x) {
	memset(visited, 0, sizeof(visited));
	queue<pii> q;
	q.push({ _y, _x });
	visited[_y][_x] = 1;

	while (!q.empty()) {
		auto [y, x] = q.front();
		q.pop();

		if (!(y == _y && x == _x) && arr[y][x] == 'K') {
			pq.push({ mp[{_y, _x}], mp[{y, x}], visited[y][x] - 1}); // 각각의 KEY 부분 엣지 삽입
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] == '1') continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

void go() {
	// 시작점에서 각각의 열쇠 위치까지 거리
	bfs(sy, sx);
	// cout << "start : \n";
	// printarr();

	// 각 열쇠 위치까지 도달 못하면 애초에 안됨
	for (auto [y, x] : key) {
		if (!visited[y][x]) {
			cout << -1 << "\n";
			exit(0);
		}
	}

	// 열쇠에서 열쇠까지 거리
	for (auto [y, x] : key) {
		bfs(y, x);
		// cout << "key => " << y << " : " << x << "\n";
		//printarr();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sy = i;
				sx = j;
				arr[i][j] = '0';
				key.push_back({ i, j });
				mp[{i, j}] = key.size();
			}
			else if (arr[i][j] == 'K') {
				key.push_back({ i, j });
				mp[{i, j}] = key.size();
			}
		}
	}
	
	for (int i = 1; i <= key.size(); i++) {
		parent[i] = i;
	}

	// cout << "key : " << key.size() << "\n";

	go();

	// MST
	while (!pq.empty()) {
		auto [s, e, v] = pq.top();
		pq.pop();

		if (findParent(s) != findParent(e)) {
			unionParent(s, e);
			res += v;
		}
	}

	cout << res << "\n";

	return 0;
}
