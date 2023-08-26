#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
vector<int> adj[100005];
int visited[100005];
int arr[100005];
int MAX;

int dfs(int here) {
	visited[here] = 1;
	int res = 1;

	for (int there : adj[here]) {
		if (visited[there] == 1)continue;
		res += dfs(there);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(&visited[0], &visited[0] + 100005, 0);
		arr[i] = dfs(i);
		MAX = max(MAX, arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (MAX == arr[i]) {
			cout << i << " ";
		}
	}


	return 0;
}