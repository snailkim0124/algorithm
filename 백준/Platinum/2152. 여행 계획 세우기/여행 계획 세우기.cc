#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, s, t;
vector<int> adj[10005], degv[10005];
int id[10005], low[10005], scc_idx[10005], deg[10005], dp[10005], scc_cnt[10005];
bool finished[10005];
stack<int> st;
int cnt;
vector<vector<int>> scc;

int dfs(int now) {
    low[now] = id[now] = ++cnt;
    st.push(now);

    for (auto next : adj[now]) {
        if (!id[next]) low[now] = min(low[now], dfs(next));
        else if (!finished[next]) low[now] = min(low[now], id[next]);
    }

    if (low[now] == id[now]) {
        vector<int> tmp;
        while (1) {
            int tt = st.top();
            st.pop();
            tmp.push_back(tt);
            scc_idx[tt] = scc.size();
            finished[tt] = true;
            if (now == tt) break;
        }
        scc.push_back(tmp);
    }

    return low[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        scc_cnt[scc_idx[i]]++;
        for (auto j : adj[i]) {
            if (scc_idx[i] != scc_idx[j]) {
                deg[scc_idx[j]]++;
                degv[scc_idx[i]].push_back(scc_idx[j]);
            }
        }
    }

    queue<int> q;
    int start = scc_idx[s];
    dp[start] = scc_cnt[start];
    q.push(start);

    int res = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == scc_idx[t]) {
            res = max(res, dp[now]);
        }

        for (auto next : degv[now]) {
            if (dp[next] < dp[now] + scc_cnt[next]) {
                dp[next] = dp[now] + scc_cnt[next];
                q.push(next);
            }
        }
    }
    
    cout << res << "\n";

    return 0;
}