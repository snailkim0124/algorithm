#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int cost[105];
vector<int> adj[105];
int id[105], low[105], deg[105];
bool finished[105];
int cnt;
stack<int> st;
vector<vector<int>> scc;
int ans;

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
            int t = st.top();
            st.pop();
            tmp.push_back(t);
            finished[t] = true;
            if (now == t) break;
        }
        scc.push_back(tmp);
    }

    return low[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i);
    }

    for (auto it : scc) {
        int tmp = INT_MAX;
        for (auto it2 : it) {
            tmp = min(tmp, cost[it2]);
        }
        ans += tmp;
    }

    cout << ans << "\n";
    
    return 0;
}