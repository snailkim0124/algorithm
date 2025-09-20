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
char arr[55][55];
int dp[55][55];
int visited[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = 0;

int go(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 'H') return 0;
    if (!visited[y][x] && dp[y][x] != -1) return dp[y][x];
    if (visited[y][x]) {
        cout << -1 << "\n";
        exit(0);
    }

    int mx = 0;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * (arr[y][x] - '0');
        int nx = x + dx[i] * (arr[y][x] - '0');
        int tmp = go(ny, nx);

        mx = max(mx, tmp);
        if (!(ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 'H')) visited[ny][nx] = 0;
    }
    
    return dp[y][x] = mx + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));

    int res = go(0, 0);

    cout << res << "\n";
    

    return 0;
}