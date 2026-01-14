#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[85][85];
map<pii, int> mp;
vector<int> adj[6405];
int visited[6405], matched[6405];
const int dy[6] = { 0,0,-1,-1,1,1 }; // 아래 대각선들도 해야함
const int dx[6] = { -1,1,-1,1,-1,1 };

bool dfs(int now) {
	for (auto next : adj[now]) {
		if (visited[next]) continue;
		visited[next] = 1;

		if (matched[next] == -1 || dfs(matched[next])) {
			matched[next] = now;
			return true;
		}
	}

	return false;
}

void make_edge(int y, int x) {
	for (int i = 0; i < 6; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] == '.') {
			adj[mp[{y, x}]].push_back(mp[{ny, nx}]);
		}
	}
}

void solve() {
	cin >> n >> m;
	int idx = 0; // 앉을 수 있는 자리
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '.') {
				mp[{i, j}] = ++idx;
			}
		}
	}

	// 양방향으로 앉을 수 있는 경우 매칭(짝수 열만)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j % 2 == 0 && arr[i][j] == '.') {
				make_edge(i, j);
			}
		}
	}

	// 최대한으로 매칭
	memset(matched, -1, sizeof(matched));
	int cnt = 0;
	for (int i = 1; i <= idx; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	//cout << idx << " : " << cnt << "\n";

	// 최대 독립 집합 = 정점 개수 - 최대 매칭
	cout << idx - cnt << "\n";

	memset(arr, 0, sizeof(arr));
	mp.clear();
	for (int i = 1; i <= idx; i++) {
		adj[i].clear();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}