#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<int> friends[1005], enemy[1005];
int visited[1005];
int cnt;

void dfs(int now) {
    for (auto next : friends[now]) {
        if (!visited[next]) {
            visited[next] = 1;
            dfs(next);
        }
    }

    // 원수의 원수는 두 겹
    for (auto next : enemy[now]) {
        for (auto next2 : enemy[next]) {
            if (!visited[next2]) {
                visited[next2] = 1;
                dfs(next2);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    while (m--) {
        char c;
        int p, q;
        cin >> c >> p >> q;
        if (c == 'F') {
            friends[p].push_back(q);
            friends[q].push_back(p);
        }
        else if (c == 'E') {
            enemy[p].push_back(q);
            enemy[q].push_back(p);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}