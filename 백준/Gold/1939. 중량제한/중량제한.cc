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
int visited[10005];
int s, e;
int res;

int bfs(int dist) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == e) return true;

        for (auto next : adj[now]) {
            int nxt = next.second;
            int nxt_dist = next.first;

            if (!visited[nxt] && nxt_dist >= dist) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    return false;
}

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

    int left = 1;
    int right = 1000000000;

    while (left <= right) {
        int mid = (left + right) / 2;
        memset(visited, 0, sizeof(visited));
        if (bfs(mid)) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << res << "\n";
    
    return 0;
}