#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int v, e;
vector<int> adj[100005];
int id[100005], low[100005], parent[100005];
vector<pii> ans;
int cnt;

void dfs(int now) {
    id[now] = low[now] = ++cnt;

    for (auto next : adj[now]) {
        if (!id[next]) {
            parent[next] = now;
            dfs(next);

            low[now] = min(low[now], low[next]);

            if (low[next] > id[now]) {
                ans.push_back({ min(now, next), max(now, next) });
            }
            
        }
        else if (next != parent[now]) {
            low[now] = min(low[now], id[next]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= v; i++) {
        if (!id[i]) dfs(i);
    }

    sort(all(ans));
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }
    

    return 0;
}
