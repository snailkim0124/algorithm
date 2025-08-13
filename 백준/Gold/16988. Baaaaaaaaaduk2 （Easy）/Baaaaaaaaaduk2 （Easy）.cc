#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[25][25];
int visited[25][25];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> v;   // 빈칸 후보
vector<pair<int, int>> opp; // 상대 돌
int mx = -1;

int solve() {
    memset(visited, 0, sizeof(visited));
    int res = 0;

    for (auto it : opp) {
        int sy = it.first, sx = it.second;
        if (visited[sy][sx]) continue;
        if (arr[sy][sx] != 2) continue; 

        queue<pair<int, int>> q;
        q.push({ sy, sx });
        visited[sy][sx] = 1;
        int cnt = 0;
        bool flag = false;

        while (!q.empty()) {
            int y, x;
            tie(y, x) = q.front(); q.pop();
            cnt++;

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (arr[ny][nx] == 0) {
                    flag = true;
                }
                else if (arr[ny][nx] == 2 && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    q.push({ ny, nx });
                }
            }
        }

        if (!flag) res += cnt;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) v.push_back({ i, j }); // 모든 빈칸 저장
            else if (arr[i][j] == 2) opp.push_back({ i, j });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            arr[v[i].first][v[i].second] = 1;
            arr[v[j].first][v[j].second] = 1;
            mx = max(mx, solve());
            arr[v[i].first][v[i].second] = 0;
            arr[v[j].first][v[j].second] = 0;
        }
    }

    cout << mx << "\n";
    return 0;
}