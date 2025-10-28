#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n;
vector<int> adj[20005];
int dist[20005], matchL[20005], matchR[20005];

bool bfs() {
	queue<int> q;
	for (int now = 0; now < n; now++) {
		if (matchL[now] == -1) {
			dist[now] = 0;
			q.push(now);
		}
		else dist[now] = INF;
	}

	dist[20004] = INF;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : adj[now]) {
			if (matchR[next] == -1) {
				dist[20004] = dist[now] + 1;
			}
			else if (dist[matchR[next]] == INF) {
				dist[matchR[next]] = dist[now] + 1;
				q.push(matchR[next]);
			}
		}
	}

	return dist[20004] != INF;
}

bool dfs(int now) {
	if (now != -1) {
		for (auto next : adj[now]) {
			if (matchR[next] == -1 || (dist[matchR[next]] == dist[now] + 1 && dfs(matchR[next]))) {
				matchL[now] = next;
				matchR[next] = now;
				return true;
			}
		}
		dist[now] = INF;
		return false;
	}
	return true;
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
		adj[i].push_back(it);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {
		cin.ignore();

		for (int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			scans(i, s);
		}

		memset(matchR, -1, sizeof(matchR));
		memset(matchL, -1, sizeof(matchL));

		int cnt = 0;
		while (bfs()) {
			for (int now = 0; now < n; now++) {
				if (matchL[now] == -1 && dfs(now)) {
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

		for (int i = 0; i < 2 * n; i++) {
			adj[i].clear();
		}
	}

	return 0;
}