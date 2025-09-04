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
int arr[1005][1005];
int tmp[1005][1005];
int tmp_size[1000005]; // 빈칸 크기
int visited[1005][1005];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

void bfs(int _y, int _x, int num) {
    int cnt = 1;
    queue<pii> q;
    visited[_y][_x] = 1;
    tmp[_y][_x] = num;
    q.push({ _y, _x });

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if (arr[ny][nx] == 0) {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
                tmp[ny][nx] = num;
                cnt++;
            }
        }
    }
    tmp_size[num] = cnt;

    return;
}

int count_wall(int y, int x) {
    int sum = 1;
    set<int> s;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        int id = tmp[ny][nx];
        if (id > 0 && !s.count(id)) {
            sum += tmp_size[id];
            s.insert(id);
        }
    }

    return sum % 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    // 빈칸에 번호 지정
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                bfs(i, j, ++num);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                cout << count_wall(i, j);
            }
            else cout << 0;
        }
        cout << "\n";
    }

    return 0;
}