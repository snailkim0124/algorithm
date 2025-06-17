#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char arr[55][55];
int visited[55][55][1 << 6];
int startx, starty;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void bfs() {
    queue<pair<pii, pii>> q;
    q.push({ {starty, startx}, {0, 0} });
    visited[starty][startx][0] = 1;

    while (!q.empty()) {
        int y, x, key, cnt;
        tie(y, x) = q.front().first;
        tie(key, cnt) = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nx < 0 || ny < 0 || ny >= n || nx >= m || visited[ny][nx][key]) continue;
            if (arr[ny][nx] == '#') continue;
            if (arr[ny][nx] == '1') {
                cout << cnt + 1 << "\n";
                return;
            }
            if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') {
                int tmp = key | (1 << (int)(arr[ny][nx] - 'a'));
                visited[ny][nx][tmp] = 1;
                q.push({ {ny, nx}, {tmp, cnt + 1} });
            }
            else if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F') {
                if (key & (1 << (int)(arr[ny][nx] - 'A'))) {
                    visited[ny][nx][key] = 1;
                    q.push({ {ny, nx}, {key, cnt + 1} });
                }
            }
            else if (arr[ny][nx] == '.') {
                visited[ny][nx][key] = 1;
                q.push({ {ny, nx}, {key, cnt + 1} });
            }

        }
    }

    cout << -1 << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') {
                starty = i;
                startx = j;
                arr[i][j] = '.';
            }
        }
    }

    bfs();

    return 0;
}
