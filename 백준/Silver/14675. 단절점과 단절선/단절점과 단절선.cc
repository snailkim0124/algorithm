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
vector<pii> v;
vector<int> adj[100005];
int id[100005], low[100005], parent[100005];
set<pii> ce;
set<int> cv;
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

            if (low[next] > id[now]) {
                ce.insert({ min(now, next), max(now, next) });
            }
            if (parent[now] == -1 && child > 1) cv.insert(now);
            if (parent[now] != -1 && low[next] >= id[now]) cv.insert(now);

        }
        else if (next != parent[now]) {
            low[now] = min(low[now], id[next]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ min(a, b), max(a, b)});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            cout << (cv.count(k) ? "yes" : "no") << "\n";
        }
        else if (t == 2) {
            cout << (ce.count(v[k - 1]) ? "yes" : "no") << "\n";
        }
    }

    return 0;
}
