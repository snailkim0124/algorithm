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
ll n, m;
ll a, b, k, g;
vector<pll> adj[1005];
ll dist[1005]; // 가중치
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<ll> gv;

ll mdist[1005][1005];
pll gdist[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> a >> b >> k >> g;
	for (int i = 0; i < g; i++) {
		int num;
		cin >> num;
		gv.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		ll u, v, l;
		cin >> u >> v >> l;
		adj[u].push_back({ v, l });
		adj[v].push_back({ u, l });

		mdist[u][v] = l;
		mdist[v][u] = l;
	}
	
	ll sum = 0;
	for (int i = 0; i < g - 1; i++) {
		int u = gv[i];
		int v = gv[i + 1];

		gdist[u][v].first = sum;
		gdist[u][v].second = sum + mdist[u][v];
		
		gdist[v][u].first = sum;
		gdist[v][u].second = sum + mdist[v][u];

		//cout << u << " : " << v << " : " << gdist[u][v].first << " : " << gdist[u][v].second << "\n";
		sum += mdist[u][v];

	}

	fill(dist, dist + 1005, INF); // 무한대 값으로 초기화
	pq.push(make_pair(k, a)); // 가중치, 시작 위치
	dist[a] = k;

	while (!pq.empty()) {
		auto [now_dist, now] = pq.top();
		pq.pop();

		if (dist[now] != now_dist) continue; // 마지막 정점인가
		for (auto [next, next_dist] : adj[now]) {
			ll ntmp = 0;
			// 진입하고 있으면 진입 못함
			if (gdist[now][next].first <= dist[now] && dist[now] < gdist[now][next].second) {
				ntmp = gdist[now][next].second + next_dist;
			}
			else {
				ntmp = dist[now] + next_dist;
			}

			if (dist[next] > ntmp) { // 더 작으면 갱신
				dist[next] = ntmp;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	cout << dist[b] - k << "\n";

	return 0;
}