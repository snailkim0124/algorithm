#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct SHARK {
    int a, b, c;
}SHARK;

int n;
SHARK arr[105];
vector<int> adj[105];
int visited[105], matched[105];

bool dfs(int now) {
    for (auto next : adj[now]) {
        if (visited[next]) continue;
        visited[next] = 1;

        if (matched[next] == -1 || dfs(matched[next])) {
            matched[next] = now;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].a == arr[j].a && arr[i].b == arr[j].b && arr[i].c == arr[j].c) {
                adj[2 * i].push_back(j);
                adj[2 * i + 1].push_back(j);
            }
            else if (arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c) {
                adj[2 * i].push_back(j);
                adj[2 * i + 1].push_back(j);
            }
            else if (arr[i].a <= arr[j].a && arr[i].b <= arr[j].b && arr[i].c <= arr[j].c) {
                adj[2 * j].push_back(i);
                adj[2 * j + 1].push_back(i);
            }
        }
    }
    
    memset(matched, -1, sizeof(matched));
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) cnt++;
    }

    cout << n - cnt << "\n";


    return 0;
}