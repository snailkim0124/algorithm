#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
int a[100005];
int visited[100005];
vector<int> adj[100005];

void dfs(int here) {
	visited[here] = 1;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (visited[there] == 0) {
			a[there] = here;
			dfs(there);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout << a[i] << "\n";
	}

	return 0;
}