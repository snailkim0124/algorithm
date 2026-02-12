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
int visited[200005];
vector<int> adj[200005], rev_adj[200005];
stack<int> st;
vector<vector<int>> res;

void dfs1(int now) {
    visited[now] = 1;

    for (auto next : adj[now]) {
        if (!visited[next]) {
            dfs1(next);
        }
    }
    st.push(now); // 순서 적기
}

void dfs2(int now, vector<int>& tmp) {
    visited[now] = 1;
    tmp.push_back(now);
    for (auto next : rev_adj[now]) {
        if (!visited[next]) {
            dfs2(next, tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        rev_adj[w].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, 0, sizeof(visited));

    while (!st.empty()) {
        int t = st.top();
        st.pop();
        if (!visited[t]) {
            vector<int> tmp;
            dfs2(t, tmp);
            res.push_back(tmp);
        }
    }

    if (res.size() == 1) {
        cout << "Yes\n";
    }
    else cout << "No\n";


    return 0;
}