#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int visited[20005];
pair<int, char> parent[20005];

void go(int now) {
	if (parent[now].first == -1) return;
	go(parent[now].first);
	cout << parent[now].second;
}

void solve() {
	memset(visited, 0, sizeof(visited));

	int n;
	cin >> n;
	
	queue<int> q;
	q.push(1);
	parent[1].first = -1;
	parent[1].second = '1';
	visited[1] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now == 0) {
			cout << "1";
			go(now);
			cout << "\n";
			return;
		}

		int tmp1 = (now * 10) % n;
		if (!visited[tmp1]) {
			visited[tmp1] = 1;
			parent[tmp1].first = now;
			parent[tmp1].second = '0';
			q.push(tmp1);
		}

		int tmp2 = (now * 10 + 1) % n;
		if (!visited[tmp2]) {
			visited[tmp2] = 1;
			parent[tmp2].first = now;
			parent[tmp2].second = '1';
			q.push(tmp2);
		}
	}

	cout << "BRAK\n";
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