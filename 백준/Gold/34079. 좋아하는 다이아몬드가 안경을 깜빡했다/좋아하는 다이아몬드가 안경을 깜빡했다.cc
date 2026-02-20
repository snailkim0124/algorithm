#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = LLONG_MAX;
int n, m;
vector<int> adj[200005];
ll dist1[200005], distn[200005];
ll cnt[200005];

void dijkstra(int s, ll dist[]) {
	fill(dist, dist + 200005, INF); // 무한대 값으로 초기화
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (dist[next] > dist[now] + 1) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dijkstra(1, dist1);
	dijkstra(n, distn);

	ll mn = dist1[n];
	//cout << "mn : " << mn << "\n";
	for (int i = 2; i <= n - 1; i++) {
		//cout << dist1[i] << " : " << distn[i] << "\n";
		if (dist1[i] != INF && distn[i] != INF && dist1[i] + distn[i] == mn) {
			cnt[dist1[i]]++;
		}
	}

	int ans = 1;
	ll mx = -1;

	for (int i = n - 1; i >= 2; i--) {
		if (dist1[i] != INF && distn[i] != INF && dist1[i] + distn[i] == mn && cnt[dist1[i]] == 1) {
			if (mx < dist1[i]) {
				mx = dist1[i];
				ans = i;
			}
		}
	}

	cout << ans << "\n";
	

	return 0;
}