#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int visited[2005];
int bigraph[2005];
vector<int> adj[2005];
bool flag = true;

void dfs(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) {
            if (bigraph[now] == 0) bigraph[next] = 1;
            else if (bigraph[now] == 1) bigraph[next] = 0;
            dfs(next);
        }
        else if (bigraph[now] == bigraph[next]) {
            flag = false;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int T = 1; T <= t; T++) {
        int n, m;
        cin >> n >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << "Scenario #" << T << ":\n";
        if (flag) cout << "No suspicious bugs found!\n";
        else cout << "Suspicious bugs found!\n";
        cout << "\n";

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        flag = true;
        memset(visited, 0, sizeof(visited));
        memset(bigraph, 0, sizeof(bigraph));

    }

    return 0;
}