#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
vector<int> adj[505];
int visited[505], matched[505];

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

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(matched, -1, sizeof(matched));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }
    
    cout << cnt << "\n";


    return 0;
}