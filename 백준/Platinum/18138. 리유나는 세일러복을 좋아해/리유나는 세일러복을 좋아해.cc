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
vector<int> adj[405];
int visited[405], matched[405];
int w[405]; // 1~200 : 티셔츠, 201~400 : 카라

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

	cin >> n >> m;
	// 티셔츠
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	// 카라
	for (int i = n + 1; i <= n + m; i++) {
		cin >> w[i];
	}

	// i : 티셔츠, j : 카라
	for (int i = 1; i <= n; i++) {
		for (int j = n + 1; j <= n + m; j++) {
			if ((w[i] <= 2 * w[j] && 4 * w[j] <= 3 * w[i]) || (w[i] <= w[j] && 4 * w[j] <= 5 * w[i])) {
				adj[i].push_back(j);
			}
		}
	}
	
	int cnt = 0;
	memset(matched, -1, sizeof(matched));

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	cout << cnt << "\n";
	

	return 0;
}