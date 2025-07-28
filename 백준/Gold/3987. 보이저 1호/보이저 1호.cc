#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char arr[505][505];
int visited[505][505][4];
int pr, pc;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int mx = -1;
char ans;

int go(int dir) {
    int y = pr;
    int x = pc;
    visited[y][x][dir] = 1;
    while (1) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        int ndir = dir;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 'C') {
            return visited[y][x][dir];
        }
        if (visited[ny][nx][ndir]) return 987654321;
        if (arr[ny][nx] == '/') {
            if (dir == 0) ndir = 1;
            else if (dir == 1) ndir = 0;
            else if (dir == 2) ndir = 3;
            else if (dir == 3) ndir = 2;
        }
        else if (arr[ny][nx] == '\\') {
            if (dir == 0) ndir = 3;
            else if (dir == 1) ndir = 2;
            else if (dir == 2) ndir = 1;
            else if (dir == 3) ndir = 0;
        }
        visited[ny][nx][ndir] = visited[y][x][dir] + 1;
        y = ny; x = nx; dir = ndir;
    }
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
    cin >> pr >> pc;
    pr--; pc--;

    for (int i = 0; i < 4; i++) {
        memset(visited, 0, sizeof(visited));
        int Time = go(i);
        if (mx < Time) {
            mx = Time;
            if (i == 0) ans = 'U';
            else if (i == 1) ans = 'R';
            else if (i == 2) ans = 'D';
            else if (i == 3) ans = 'L';
        }
    }

    cout << ans << "\n";
    if (mx == 987654321) cout << "Voyager";
    else cout << mx;

    return 0;
}