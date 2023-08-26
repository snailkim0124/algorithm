#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <map>

using namespace std;
int n,tmp;
int root;
int num;
vector<int> adj[55];

int dfs(int here) {
	int res = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == num) continue;
		res += dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == -1) root = i;
		else adj[tmp].push_back(i);
	}

	cin >> num;
	if (num == root) {
		cout << 0;
		exit(0);
	}

	cout << dfs(root);

	return 0;
}