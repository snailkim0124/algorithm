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
int arr[105][105];
vector<int> adj[10005];
int visited[10005], matched[10005];
int rnum[105][105], cnum[105][105];


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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ridx = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true; // 연결되는지 확인
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				flag = true;
			}
			else {
				if (flag) {
					flag = false;
					ridx++;
				}
				rnum[i][j] = ridx;
			}
		}
	}

	int cidx = 0;
	for (int j = 0; j < m; j++) {
		bool flag = true; // 연결되는지 확인
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 2) {
				flag = true;
			}
			else {
				if (flag) {
					flag = false;
					cidx++;
				}
				cnum[i][j] = cidx;
			}
		}
	}

	//cout << "==================\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << rnum[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "==================\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << cnum[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "==================\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				adj[rnum[i][j]].push_back(cnum[i][j]);
			}
		}
	}

	memset(matched, -1, sizeof(matched));
	int cnt = 0;
	for (int i = 1; i <= ridx; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}