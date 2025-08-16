#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int r, c;
char arr[20][20];
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };
vector<pii> goal;
string s;
int cy, cx;

bool check_box(int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (arr[ny][nx] == 'b' || arr[ny][nx] == 'B' || arr[ny][nx] == '#') return false;
    return true;
}

void move_box(int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];


    if (arr[ny][nx] == '+') arr[ny][nx] = 'B';
    else arr[ny][nx] = 'b';

    if (arr[y][x] == 'B') arr[y][x] = '+';
    else arr[y][x] = '.';
}

void move_char(int dir) {
    int ny = cy;
    int nx = cx;

    ny += dy[dir];
    nx += dx[dir];

    if (arr[ny][nx] == '#') {
        // 못 움직임
        ny = cy;
        nx = cx;
        return;
    }
    else if (arr[ny][nx] == 'b' || arr[ny][nx] == 'B') {
        if (check_box(ny, nx, dir)) {
            move_box(ny, nx, dir);
        }
        else {
            // 못 움직임
            ny = cy;
            nx = cx;
            return;
        }
    }

    // 움직임
    if (arr[cy][cx] == 'W') arr[cy][cx] = '+';
    else arr[cy][cx] = '.';

    if (arr[ny][nx] == '+') arr[ny][nx] = 'W';
    else arr[ny][nx] = 'w';

    cy = ny;
    cx = nx;
}

bool check_end() {
    for (auto it : goal) {
        if (arr[it.first][it.second] != 'B') return false;
    }
    return true;
}

void print_arr() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    for (int T = 1; ; T++) {
        memset(arr, 0, sizeof(arr));
        goal.clear();

        bool flag = false;
        cin >> r >> c;
        if (!r && !c) break;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 'w' || arr[i][j] == 'W') {
                    cy = i;
                    cx = j;
                }
                if (arr[i][j] == '+' || arr[i][j] == 'W' || arr[i][j] == 'B') {
                    goal.push_back({ i, j });
                }
            }
        }

        cin >> s;
        for (auto cmd : s) {
            if (cmd == 'U') move_char(0);
            else if (cmd == 'D') move_char(1);
            else if (cmd == 'L') move_char(2);
            else if (cmd == 'R') move_char(3);

            if (check_end()) {
                flag = true;
                break;
            }
        }

        cout << "Game " << T << ": " << (flag ? "complete" : "incomplete") << "\n";
        print_arr();
    }

    return 0;
}