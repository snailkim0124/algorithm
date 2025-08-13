#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct FIRE {
    int r, c, m, s, d;
}FIRE;

int n, m, k;
vector<FIRE> arr[55][55];
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<FIRE> v;
int sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    while (m--) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        v.push_back({ r,c,m,s,d });
    }

    while (k--) {
        vector<FIRE> tmp = v;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j].clear();
            }
        }

        // 이동
        for (auto it : tmp) {
            int ns = it.s % n;
            int ny = ((it.r - 1 + dy[it.d] * ns) % n + n) % n + 1;
            int nx = ((it.c - 1 + dx[it.d] * ns) % n + n) % n + 1;
            arr[ny][nx].push_back({ ny, nx, it.m, it.s, it.d });
        }

        vector<FIRE> tmp2;

        // 나눠짐
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j].size() == 1) {
                    tmp2.push_back(arr[i][j][0]);
                }
                else if (arr[i][j].size() >= 2) {
                    int sumM = 0, sumS = 0;
                    bool allOdd = true, allEven = true;

                    for (auto it : arr[i][j]) {
                        sumM += it.m;
                        sumS += it.s;
                        if (it.d % 2 == 0) allOdd = false;
                        else allEven = false;
                    }

                    int newM = sumM / 5;
                    if (newM == 0) continue;

                    int newS = sumS / arr[i][j].size();
                    for (int dir = 0; dir < 4; ++dir) {
                        int newD = (allOdd || allEven) ? dir * 2 : dir * 2 + 1;
                        tmp2.push_back({ i, j, newM, newS, newD });
                    }
                }
            }
        }

        v = tmp2;
    }

    // 질량합
    for (auto it : v) {
        sum += it.m;
    }

    cout << sum;

    return 0;
}