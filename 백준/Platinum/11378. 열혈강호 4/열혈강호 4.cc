#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, k;
vector<int> adj[1005];
int visited[1005], matched[1005];

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

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int num;
            cin >> num;
            adj[i].push_back(num);
        }
    }

    memset(matched, -1, sizeof(matched));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) res++;
    }

    int cnt = 0;
    // 한번 더 돌리기
    while (1) {
        bool flag = false;
        for (int i = 1; i <= n && k > 0; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) {
                res++;
                flag = true;
                k--;
            }
        }
        if (!flag) break;
    }

    cout << res << "\n";

    return 0;
}