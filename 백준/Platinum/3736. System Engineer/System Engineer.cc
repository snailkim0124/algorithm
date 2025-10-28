#include <bits/stdc++.h>
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

void scans(int i, string s) {
	vector<int> v;

	string rev_s = s;
	reverse(all(rev_s));

	int idx = 0;
	while (1) {
		if (rev_s[idx] == ')') break;

		bool flag = false;
		string tmp = "";

		while (isdigit(rev_s[idx])) {
			flag = true;
			tmp += rev_s[idx];
			idx++;
		}
		
		if (flag) {
			reverse(all(tmp));
			v.push_back(stoi(tmp));
		}
		else idx++;
	}


	for (auto it : v) {
		//cout << it << " ";
		adj[i].push_back(it);
	}
	//cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	while (cin >> n) {
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			scans(i, s);
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