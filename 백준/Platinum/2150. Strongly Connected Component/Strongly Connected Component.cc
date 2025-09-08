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
int visited[10005];
vector<int> adj[10005], rev_adj[10005];
vector<int> order;
vector<vector<int>> res;

void dfs1(int now) {
    visited[now] = 1;

    for (auto next : adj[now]) {
        if (!visited[next]) {
            dfs1(next);
        }
    }
    order.push_back(now); // 순서 적기
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

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for (int i = 1; i <= v; i++) {
        if (!visited[i]) dfs1(i);
    }
    
    reverse(all(order)); // 순서 뒤집기
    memset(visited, 0, sizeof(visited));

    for (auto it : order) {
        if (!visited[it]) {
            vector<int> tmp;
            dfs2(it, tmp);
            sort(all(tmp));

            res.push_back(tmp);
        }
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