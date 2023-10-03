#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, M, K;
ll dist[100005]; // 가중치
const ll INF = 1e18;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
vector<pair<ll, ll>> adj[100005];
ll arr[100005];
ll city[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(dist, dist + 100005, INF); // 무한대 값으로 초기화

	cin >> N >> M >> K; // 방의 개수, 비밀통로 개수

	for (int i = 0; i < M; i++) {
		ll u, v, c; // u에서 v까지 c만큼 길이
		cin >> u >> v >> c;
		adj[v].push_back(make_pair(c, u));
	}

	ll mx = 0;
	ll res = 0;
	for (int i = 0; i < K; i++) {
		cin >> city[i];
	}

	for (int i = 0; i < K; i++) { // 가중치, 시작 위치
		pq.push(make_pair(0, city[i])); 
		dist[city[i]] = 0;
	}
	
		
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

	for (int j = 1; j <= N; j++) { // 총합 거리 계산
		if (dist[j] != INF && mx < dist[j]) {
			mx = dist[j];
			res = j;
		}
	}

	cout << res << "\n";
	cout << mx;

	return 0;
}