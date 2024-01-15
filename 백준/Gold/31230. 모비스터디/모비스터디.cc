#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M, A, B;
ll dist[200005]; // 가중치
const ll INF = ll(10e16);
vector<pair<ll, ll>> adj[200005];
vector<ll> v;
ll Adist[200005];

void dijkstra(ll start) {
	fill(dist, dist + 200005, INF); // 무한대 값으로 초기화
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push(make_pair(0, start)); // 가중치, 시작 위치
	dist[start] = 0;
	while (!pq.empty()) {
		ll here = pq.top().second;
		ll here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue; // 마지막 정점인가
		for (pair<ll, ll> there : adj[here]) {
			ll _dist = there.first;
			ll _there = there.second;
			if (dist[_there] > dist[here] + _dist) { // 더 작으면 갱신
				dist[_there] = dist[here] + _dist;
				pq.push(make_pair(dist[_there], _there));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> A >> B;

	for (ll i = 0; i < M; i++) {
		ll u, v, w; // u에서 v까지 가중치 w
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
		adj[v].push_back(make_pair(w, u));
	}

	fill(Adist, Adist + 200005, INF); // 무한대 값으로 초기화

	dijkstra(A);
	ll AtoB = dist[B];

	for (ll i = 1; i <= N; i++) {
		Adist[i] = dist[i];
	}

	dijkstra(B);

	for (ll i = 1; i <= N; i++) {
		if (Adist[i] + dist[i] == AtoB) {
			v.push_back(i);
		}
	}

	cout << v.size() << "\n";

	for (auto it : v) {
		cout << it << " ";
	}


	return 0;
}