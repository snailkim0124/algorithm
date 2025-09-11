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
vector<int> adj[20005], rev_adj[20005];
int visited[20005], scc_idx[20005];
stack<int> st;

void dfs1(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) dfs1(next);
    }
    st.push(now);
}

void dfs2(int now, int idx) {
    visited[now] = 1;
    scc_idx[now] = idx;
    for (auto next : rev_adj[now]) {
        if (!visited[next]) dfs2(next, idx);
    }
}

int change(int x) {
    return x < 0 ? -x * 2 : x * 2 + 1;
}

int neg(int x) {
    return (x % 2 == 0 ? x + 1 : x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x = change(x);
        y = change(y);

        adj[neg(x)].push_back(y);
        adj[neg(y)].push_back(x);

        rev_adj[y].push_back(neg(x));
        rev_adj[x].push_back(neg(y));
    }


    for (int i = 1; i <= 2 * n; i++) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, 0, sizeof(visited));

    int idx = 0;
    while (!st.empty()) {
        int tt = st.top();
        st.pop();

        if (!visited[tt]) {
            dfs2(tt, ++idx);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (scc_idx[2 * i] == scc_idx[2 * i + 1]) {
            cout << "OTL\n";
            exit(0);
        }
    }

    cout << "^_^\n";

    return 0;
}