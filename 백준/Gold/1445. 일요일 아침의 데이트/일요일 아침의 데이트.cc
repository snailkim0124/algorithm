#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
char arr[55][55];
int visited[55][55]; // 쓰레기
int visited2[55][55]; // 주변 쓰레기
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
int starty, startx, endy, endx;
const int INF = 987654321;
vector<pii> gv;
vector<pii> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'S') {
                starty = i;
                startx = j;
            }
            else if (arr[i][j] == 'F') {
                endy = i;
                endx = j;
            }
            else if (arr[i][j] == 'g') {
                gv.push_back({ i ,j });
            }
        }
    }


    for (auto [i, j] : gv) {
        for (int dir = 0; dir < 4; dir++) {
            int ny = i + dy[dir];
            int nx = j + dx[dir];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (arr[ny][nx] == '.') arr[ny][nx] = '@'; // 쓰레기 주변 표시
        }
    }

    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << arr[i][j];
    //    }
    //    cout << "\n";
    //}

    priority_queue<tii, vector<tii>, greater<tii>> pq;
    fill(&visited[0][0], &visited[0][0] + 55 * 55, INF);
    fill(&visited2[0][0], &visited2[0][0] + 55 * 55, INF);

    pq.push({ 0, 0, starty, startx });
    visited[starty][startx] = 0;
    visited2[starty][startx] = 0;
    
    while (!pq.empty()) {
        auto [g_cnt, gn_cnt, y, x] = pq.top();
        pq.pop();

        if (y == endy && x == endx) {
            cout << g_cnt << " " << gn_cnt << "\n";
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            int ng = g_cnt + (arr[ny][nx] == 'g');
            int ngn = gn_cnt + (arr[ny][nx] == '@');

            if (ng < visited[ny][nx] || (ng == visited[ny][nx] && ngn < visited2[ny][nx])) {
                visited[ny][nx] = ng;
                visited2[ny][nx] = ngn;

                pq.push({ ng, ngn, ny, nx });
            }
        }
    }

    return 0;
}