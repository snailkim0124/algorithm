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
vector<int> adj[100005], rev_adj[100005];
int visited[100005];
stack<int> st;

void dfs1(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) dfs1(next);
    }
    st.push(now);
}

void dfs2(int now, vector<int>& tmp) {
    visited[now] = 1;
    tmp.push_back(now);

    for (auto next : rev_adj[now]) {
        if (!visited[next]) dfs2(next, tmp);
    }
}

void check(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) check(next);
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
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            rev_adj[b].push_back(a);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs1(i);
        }

        memset(visited, 0, sizeof(visited));

        // 가장 마지막 노드에서 다 돌수 있는지 체크
        check(st.top());
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) flag = false;
        }

        if (flag) {
            memset(visited, 0, sizeof(visited));
            vector<int> res;
            dfs2(st.top(), res);
            sort(all(res));
            for (auto it : res) {
                cout << it << "\n";
            }
        }
        else cout << "Confused\n";
        cout << "\n";

        // 초기화
        memset(visited, 0, sizeof(visited));
        st = stack<int>();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            rev_adj[i].clear();
        }

    }


    return 0;
}