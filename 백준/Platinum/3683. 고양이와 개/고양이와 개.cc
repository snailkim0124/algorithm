#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int c, d, v;
vector<int> adj[505];
vector<tii> cat, dog;
int visited[505], matched[505];

pair<char, int> catdog(string s) {
	char ani = s[0];
	string num = s.substr(1, s.size());

	return { ani, stoi(num) };
}

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

void solve() {
	cin >> c >> d >> v;
	for (int i = 1; i <= v; i++) {
		string a, b;
		cin >> a >> b;

		auto [aani, anum] = catdog(a);
		auto [bani, bnum] = catdog(b);
		
		if (aani == 'C') {
			cat.push_back({ i, anum, bnum });
		}
		else if (aani == 'D') {
			dog.push_back({ i, anum, bnum });
		}
	}

	for (auto [a, al, ad] : cat) {
		for (auto [b, bl, bd] : dog) {
			if (al == bd || ad == bl) {
				adj[a].push_back(b);
			}
		}
	}

	int cnt = 0;
	memset(matched, -1, sizeof(matched));

	for (auto [a, al, ad] : cat) {
		memset(visited, 0, sizeof(visited));
		if (dfs(a)) cnt++;
	}

	cout << v - cnt << "\n";

	for (int i = 1; i <= v; i++) {
		adj[i].clear();
	}
	cat.clear();
	dog.clear();


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