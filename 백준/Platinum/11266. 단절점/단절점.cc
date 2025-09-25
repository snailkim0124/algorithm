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
vector<int> adj[10005];
int id[10005], low[10005], parent[10005];
bool ap[10005];
int cnt;

void dfs(int now) {
    id[now] = low[now] = ++cnt;

    int child = 0;

    for (auto next : adj[now]) {
        if (!id[next]) {
            child++;
            parent[next] = now;
            dfs(next);

            low[now] = min(low[now], low[next]);

            if (parent[now] == -1 && child > 1) ap[now] = true; // 루트 노드
            if (parent[now] != -1 && low[next] >= id[now]) ap[now] = true; // 자식이 자신보다 크거나 같으면
        }
        else if (next != parent[now]) {
            low[now] = min(low[now], id[next]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= v; i++) {
        if (!id[i]) dfs(i);
    }

    vector<int> ans;
    for (int i = 1; i <= v; i++) {
        if (ap[i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it << " ";
    }
    

    return 0;
}
