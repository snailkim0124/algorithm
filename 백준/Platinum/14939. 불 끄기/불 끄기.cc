#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int arr[15][15];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = INT_MAX;

void go(int y, int x) {
    arr[y][x] ^= 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
        arr[ny][nx] ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == 'O') arr[i][j] = 1;
            else if (c == '#') arr[i][j] = 0;
        }
    }

    int tmp[15][15] = { 0 };
    memcpy(tmp, arr, sizeof(arr));

    for (int mask = 0; mask < (1 << 10); mask++) {
        int cnt = 0;

        memcpy(arr, tmp, sizeof(tmp));

        // 첫 행을 미리 판단
        for (int i = 0; i < 10; i++) {
            if (mask & (1 << i)) {
                go(0, i);
                cnt++;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                if (arr[i][j] == 1) {
                    // 전에 행이 켜져있으면 끄기 위해 다음 행이 해결
                    go(i + 1, j);
                    cnt++;
                }
            }
        }

        // 마지막 행 남아있으면 안됨
        bool flag = true;
        for (int j = 0; j < 10; j++) {
            if (arr[9][j] == 1) {
                flag = false;
                break;
            }
        }

        if(flag) res = min(res, cnt);
    }

    if (res == INT_MAX) cout << -1 << "\n";
    else cout << res << "\n";

    return 0;
}