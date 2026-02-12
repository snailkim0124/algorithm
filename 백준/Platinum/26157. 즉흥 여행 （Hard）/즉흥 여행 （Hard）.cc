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
int id[200005], low[200005], scc_idx[200005];
bool finished[200005];
vector<int> adj[200005];
vector<vector<int>> res;
stack<int> st;
int cnt, idx;

int dfs(int now) {
    low[now] = id[now] = ++cnt;
    st.push(now);

    for (auto next : adj[now]) {
        if (!id[next]) low[now] = min(low[now], dfs(next));
        else if (!finished[next]) low[now] = min(low[now], id[next]);
    }

    if (id[now] == low[now]) {
        vector<int> tmp;
        while (1) {
            int tt = st.top();
            st.pop();
            scc_idx[tt] = idx;
            finished[tt] = true;
            tmp.push_back(tt);
            if (tt == now) break;
        }

        sort(all(tmp));
        res.push_back(tmp);
        idx++;
    }

    return low[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i);
    }

    for (int i = idx - 1; i > 0; i--) {
        bool flag = false;
        for (auto u : res[i]) {
            for (auto v : adj[u]) {
                if (scc_idx[v] == i - 1) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) {
            cout << "0\n";
            exit(0);
        }
    }


    cout << res.back().size() << "\n";
    for (auto it : res.back()) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}