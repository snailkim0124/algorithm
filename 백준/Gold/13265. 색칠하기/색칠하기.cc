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
int n, m;
int visited[1005];
int bigraph[1005];
vector<int> adj[1005];
bool flag = true;

void dfs(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) {
            if (bigraph[now] == 0) bigraph[next] = 1;
            else if (bigraph[now] == 1) bigraph[next] = 0;
            dfs(next);

        }
        else if (bigraph[next] == bigraph[now]) {
            flag = false;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << (flag ? "possible" : "impossible") << "\n";

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        
        flag = true;
        memset(visited, 0, sizeof(visited));
        memset(bigraph, 0, sizeof(bigraph));
    }


    return 0;
}