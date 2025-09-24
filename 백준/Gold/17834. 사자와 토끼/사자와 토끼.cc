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
int visited[50005];
int bigraph[50005];
vector<int> adj[50005];
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

    if (flag) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (bigraph[i] == 1) cnt1++;
            else if (bigraph[i] == 0) cnt2++;
        }

        cout << cnt1 * cnt2 * 2 << "\n";
    }
    else cout << 0 << "\n";

    return 0;
}