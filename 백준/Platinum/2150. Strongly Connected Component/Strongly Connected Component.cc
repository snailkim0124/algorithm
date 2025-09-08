#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int v, e;
bool finished[10005];
int id[10005], low[10005];
vector<int> adj[10005];
vector<vector<int>> res;
stack<int> st;
int cnt;

int dfs(int now) {
    id[now] = low[now] = ++cnt;
    st.push(now);

    for (auto next : adj[now]) {
        if (!id[next]) low[now] = min(low[now], dfs(next));
        else if(!finished[next]) low[now] = min(low[now], id[next]);
    }

    if (id[now] == low[now]) {
        vector<int> tmp;
        while (1) {
            int t = st.top();
            st.pop();
            finished[t] = true;
            tmp.push_back(t);
            if (t == now) break;
        }
        sort(all(tmp));
        res.push_back(tmp);
    }

    return low[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= v; i++) {
        if (!id[i]) dfs(i);
    }
    
    sort(all(res));
    cout << res.size() << "\n";
    for (auto it : res) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << "-1\n";
    }
    

    return 0;
}