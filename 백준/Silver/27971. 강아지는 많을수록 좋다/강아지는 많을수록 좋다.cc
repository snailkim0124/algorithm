#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, a, b;
int visited[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> a >> b;
	while (m--) {
		int l, r;
		cin >> l >> r;
		for (int i = l; i <= r; i++) {
			visited[i] = 1;
		}
	}

	queue<pii> q;
	q.push({ 0,0 });
	visited[0] = 1;
	while (!q.empty()) {
		auto [now, cnt] = q.front();
		q.pop();

		if (now == n) {
			cout << cnt << "\n";
			exit(0);
		}

		if (now + a <= 100000 && !visited[now + a]) {
			visited[now + a] = 1;
			q.push({ now + a, cnt + 1 });
		}
		if (now + b <= 100000 && !visited[now + b]) {
			visited[now + b] = 1;
			q.push({ now + b , cnt + 1 });
		}
	}
	
	cout << -1 << "\n";
	
	return 0;
}