#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll visited[100005];
ll bigraph[100005];
vector<ll> adj[100005];
ll white[100005], black[100005];

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
    for (int i = 0; i < n - 1; i++) {
        ll p, c;
        cin >> p >> c;
        adj[p].push_back(c);
        adj[c].push_back(p);
    }

    for (int i = 0; i < n; i++) {
        cin >> white[i] >> black[i];
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }
    
    ll sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++) {
        if (bigraph[i] == 0) {
            sum1 += white[i];
            sum2 += black[i];
        }
        else if (bigraph[i] == 1) {
            sum1 += black[i];
            sum2 += white[i];
        }
    }

    cout << min(sum1, sum2) << "\n";


    return 0;
}