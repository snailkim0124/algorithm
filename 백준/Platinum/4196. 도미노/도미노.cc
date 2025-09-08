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
int visited[100005];
vector<int> adj[100005];
stack<int> st;

void dfs1(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) dfs1(next);
    }
    st.push(now);
}

void dfs2(int now) {
    visited[now] = 1;

    for (auto next : adj[now]) {
        if (!visited[next]) dfs2(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs1(i);
        }

        memset(visited, 0, sizeof(visited));

        int cnt = 0;
        while (!st.empty()) {
            int tt = st.top();
            st.pop();

            if (!visited[tt]) {
                dfs2(tt);
                cnt++;
            }
        }

        cout << cnt << "\n";

        // 초기화
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        st = stack<int>();
    }


    return 0;
}