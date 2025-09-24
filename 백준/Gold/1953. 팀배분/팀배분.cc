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
int visited[105];
int bigraph[105];
vector<int> adj[105];
vector<int> b, w;

void dfs(int now) {
    visited[now] = 1;
    for (auto next : adj[now]) {
        if (!visited[next]) {
            if (bigraph[now] == 0) bigraph[next] = 1;
            else if (bigraph[now] == 1) bigraph[next] = 0;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int j;
            cin >> j;
            adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (bigraph[i] == 1) b.push_back(i);
        else if (bigraph[i] == 0) w.push_back(i);
    }

    cout << b.size() << "\n";
    for (auto it : b) {
        cout << it << " ";
    }
    cout << "\n";

    cout << w.size() << "\n";
    for (auto it : w) {
        cout << it << " ";
    }
    cout << "\n";
    
    

    return 0;
}