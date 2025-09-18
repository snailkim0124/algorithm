#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int w, h;
char arr[25][25];
int visited[25][25];
int sy, sx;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pii> wastev;
const int INF = 987654321;
int stow[25], wtow[25][25];
int dp[10][1 << 10];

void bfs(int _y, int _x) {
    fill(&visited[0][0], &visited[0][0] + 25 * 25, INF);
    queue<pii> q;
    q.push({ _y, _x });
    visited[_y][_x] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= h || nx >= w || arr[ny][nx] == 'x') continue;
            if (visited[ny][nx] > visited[y][x] + 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    // printarr();
}

int go(int bit, int idx, int n) {
    if (bit == (1 << n) - 1) return 0; // 모든 쓰레기 방문
    if (dp[idx][bit] != -1) return dp[idx][bit];

    int res = INF;
    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) continue;
        if (wtow[idx][i] == INF) continue;
        res = min(res, wtow[idx][i] + go(bit | (1 << i), i, n));
    }

    return dp[idx][bit] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        memset(stow, 0, sizeof(stow));
        memset(wtow, 0, sizeof(wtow));
        wastev.clear();
        memset(arr, 0, sizeof(arr));
        cin >> w >> h;
        if (!w && !h) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'o') {
                    sy = i;
                    sx = j;
                    arr[i][j] = '.';
                }
                else if (arr[i][j] == '*') {
                    wastev.push_back({ i, j });
                }
            }
        }

        bfs(sy, sx);

        // 시작 지점에서 다른 쓰레기까지 최단거리
        for (int i = 0; i < wastev.size(); i++) {
            stow[i] = visited[wastev[i].first][wastev[i].second];
        }

        // 쓰레기에서 쓰레기까지 최단 거리
        for (int i = 0; i < wastev.size(); i++) {
            bfs(wastev[i].first, wastev[i].second);
            for (int j = 0; j < wastev.size(); j++) {
                if (i == j) continue;
                wtow[i][j] = visited[wastev[j].first][wastev[j].second];
            }
        }

        int ans = INF;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < wastev.size(); i++) {
            if (stow[i] == INF) continue;
            ans = min(ans, stow[i] + go(1 << i, i, wastev.size()));
        }

        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}