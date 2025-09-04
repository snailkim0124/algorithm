#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
const int INF = INT_MAX;
vector<pii> adj[10005];
int dist[10005];
priority_queue<pii, vector<pii>> pq;
int s, e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    cin >> s >> e;

    fill(dist, dist + 10005, -1);
    pq.push({ INF, s }); // 가중치, 시작위치
    dist[s] = INF;
    while (!pq.empty()) {
        int now = pq.top().second;
        int now_dist = pq.top().first;
        pq.pop();

        if (dist[now] > now_dist) continue;

        for (pii next : adj[now]) {
            int nxt = next.second;
            int next_dist = min(now_dist, next.first);

            if (dist[nxt] < next_dist) {
                dist[nxt] = next_dist;
                pq.push({ dist[nxt] , nxt });
            }
        }
    }

    cout << dist[e] << "\n";


    return 0;
}