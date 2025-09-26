#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[1005][1005];
int visited[1005][1005];
int cnt = 1;
set<int> s;

int dfs(int y, int x) {
    if (visited[y][x]) return visited[y][x];

    visited[y][x] = cnt;

    if (arr[y][x] == 'N') {
        return visited[y][x] = dfs(y - 1, x);
    }
    else if (arr[y][x] == 'W') {
        return visited[y][x] = dfs(y, x - 1);
    }
    else if (arr[y][x] == 'E') {
        return visited[y][x] = dfs(y, x + 1);
    }
    else if (arr[y][x] == 'S') {
        return visited[y][x] = dfs(y + 1, x);
    }
}

void printarr() {
    cout << "=============================\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "=============================\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    // printarr();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s.insert(visited[i][j]);
        }
    }

    cout << s.size() << "\n";

    return 0;
}