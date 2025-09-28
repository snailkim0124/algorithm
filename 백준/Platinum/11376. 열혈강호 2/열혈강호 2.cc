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
vector<int> adj[2005];
int visited[2005], matched[2005];

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

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int work;
        cin >> work;
        for (int j = 0; j < work; j++) {
            int num;
            cin >> num;
            adj[i * 2 - 1].push_back(num);
            adj[i * 2].push_back(num);
        }
    }

    int cnt = 0;
    memset(matched, -1, sizeof(matched));

    for (int i = 1; i <= 2 * n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }

    //for (int i = 1; i <= n; i++) {
    //    cout << i << " : " << matched[i] << "\n";
    //}

    cout << cnt << "\n";
    
    return 0;
}