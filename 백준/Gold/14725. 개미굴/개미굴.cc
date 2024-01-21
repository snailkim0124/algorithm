#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans;
const int ROOT = 1;
int unused = 2;
const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];

void insert(vector<string>& v) {
	int cur = ROOT;
	for (auto s : v) {
		if (!nxt[cur][s]) {
			nxt[cur][s] = unused++;
		}
		cur = nxt[cur][s];
	}
}

void dfs(int now, int depth) {
	for (auto there : nxt[now]) {
		for (int i = 0; i < depth; i++) {
			cout << "--";
		}
		cout << there.first << "\n";
		dfs(there.second, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<string> v(m);
		for (int j = 0; j < m; j++) {
			cin >> v[j];
		}
		insert(v);
	}

	dfs(1, 0);

	return 0;
}