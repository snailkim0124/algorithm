#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c, n;
int arr[305][305];
vector<int> adj[605];
int visited[605], matched[605];

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> n;
	for (int i = 0; i < n; i++) {
		int y, x;
		cin >> y >> x;
		arr[y][x] = 1;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!arr[i][j]) {
				adj[i].push_back(r + j);
			}
		}
	}

	memset(matched, -1, sizeof(matched));
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	cout << cnt << "\n";



	return 0;
}