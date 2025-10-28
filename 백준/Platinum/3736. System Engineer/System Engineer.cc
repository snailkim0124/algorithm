#include <bits/stdc++.h>
#include <regex>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> adj[20005];
int visited[20005], matched[20005];


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

void scans(string s) {
	int num;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	regex re(R"(^\s*(\d+)\s*:\s*\(\s*(\d+)\s*\)\s*((\d+\s*)+)$)");

	int n;
	while (cin >> n) {
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			smatch match;
			vector<int> v;

			if (regex_match(s, match, re)) {
				int job = stoi(match[1].str());
				int nr = stoi(match[2].str());
				stringstream ss(match[3].str());

				int x;
				while (ss >> x) {
					v.push_back(x);
				}

			}

			for (auto it : v) {
				adj[i].push_back(it);
			}

		}

		memset(matched, -1, sizeof(matched));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}

		cout << cnt << "\n";

		for (int i = 0; i < 2 * n; i++) {
			adj[i].clear();
		}
	}
	
	return 0;
}