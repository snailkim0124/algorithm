#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k, n;
vector<int> adj[10005], rev_adj[10005];
int visited[10005], scc_idx[10005];
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

int neg(int x) {
    return x > k ? x - k : x + k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < 3; j++) {
            int l; char c;
            cin >> l >> c;

            // R은 R끼리 B는 B끼리
            if (c == 'R') {
                v.push_back(l);
            }
            else if (c == 'B') {
                v.push_back(l + k);
            }
        }

        for (int j = 0; j < 3; j++) {
            int a = v[j];
            int b = v[(j + 1) % 3];

            adj[neg(a)].push_back(b);
            adj[neg(b)].push_back(a);

            rev_adj[b].push_back(neg(a));
            rev_adj[a].push_back(neg(b));
        }
    }

    for (int i = 1; i <= 2 * k; i++) {
        if (!visited[i]) dfs1(i);
    }

    memset(visited, 0, sizeof(visited));

    int idx = 0;
    while (!st.empty()) {
        int t = st.top();
        st.pop();

        if (!visited[t]) {
            dfs2(t, ++idx);
        }
    }

    vector<char> ans;
    for (int i = 1; i <= k; i++) {
        if (scc_idx[i] == scc_idx[i + k]) {
            cout << -1 << "\n";
            exit(0);
        }
        else if (scc_idx[i] > scc_idx[i + k]) {
            ans.push_back('R');
        }
        else ans.push_back('B');
    }

    for (auto it : ans) {
        cout << it;
    }
    cout << "\n";
    
    return 0;
}