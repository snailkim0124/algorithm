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
int visited[1005], matched[1005];
vector<int> adj[1005];

bool dfs(int now) {
    for (auto next : adj[now]) {
        if (visited[next]) continue;
        visited[next] = 1;

        if (matched[next] == -1 || dfs(matched[next])) {
            matched[next] = now;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            for (int j = a; j <= b; j++) {
                adj[i].push_back(j);
            }
        }

        int cnt = 0;
        memset(matched, -1, sizeof(matched));
        for (int i = 1; i <= m; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) cnt++;
        }

        cout << cnt << "\n";

        for (int i = 1; i <= m; i++) {
            adj[i].clear();
        }
    }


    return 0;
}