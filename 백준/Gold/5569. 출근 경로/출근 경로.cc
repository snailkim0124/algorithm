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
int dp[105][105][4]; // 옆, 옆아래, 아래옆, 아래
const int mod = 100000;
int res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> w >> h; 

    for (int i = 1; i <= w; i++) {
        dp[1][i][0] = 1;
    }

    for (int i = 1; i <= h; i++) {
        dp[i][1][3] = 1;
    }

    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
            dp[i][j][2] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i][j - 1][3];
            dp[i][j][3] = (dp[i - 1][j][2] + dp[i - 1][j][3]) % mod;
        }
    }

    for (int k = 0; k < 4; k++) {
        res = (res + dp[h][w][k]) % mod;
    }
    cout << res;

    return 0;
}