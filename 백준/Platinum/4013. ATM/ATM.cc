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
vector<int> adj[500005];
int money[500005];
int s, p;
int isres[500005];
int id[500005], low[500005], scc_idx[500005], deg[500005];
int scc_res[500005], scc_money[500005], dp[500005];
vector<int> degv[500005];
bool finished[500005];
int cnt;
stack<int> st;
vector<vector<int>> res;

int dfs(int now) {
    id[now] = low[now] = ++cnt;
    st.push(now);

    for (auto next : adj[now]) {
        if (!id[next]) low[now] = min(low[now], dfs(next));
        else if (!finished[next]) low[now] = min(low[now], id[next]);
    }

    if (low[now] == id[now]) {
        vector<int> tmp;
        while (1) {
            int t = st.top();
            st.pop();
            scc_idx[t] = res.size();
            finished[t] = true;
            tmp.push_back(t);
            if (now == t) break;
        }
        res.push_back(tmp);
    }

    return low[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }

    cin >> s >> p;
    for (int i = 0; i < p; i++) {
        int num;
        cin >> num;
        isres[num] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i);
    }

    // scc 단위로 돈 총액과 레스토랑 여부 확인
    for (int i = 0; i < res.size(); i++) {
        for (auto it : res[i]) {
            scc_money[i] += money[it];
            if (isres[it]) scc_res[i] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (auto j : adj[i]) {
            if (scc_idx[i] != scc_idx[j]) {
                deg[scc_idx[j]]++;
                degv[scc_idx[i]].push_back(scc_idx[j]);
            }
        }
    }

    queue<int> q;
    int start = scc_idx[s];
    dp[start] = scc_money[start];

    for (int i = 0; i < res.size(); i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : degv[now]) {
            if (dp[now]) dp[next] = max(dp[next], dp[now] + scc_money[next]);
            deg[next]--;
            if (deg[next] == 0) q.push(next);
        }
    }

    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        if (scc_res[i]) ans = max(ans, dp[i]); // 레스토랑에 도착한 경우
    }

    cout << ans << "\n";

    return 0;
}