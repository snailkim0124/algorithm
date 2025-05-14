#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int dp[100005];
int money[5] = {1,2,5,7};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;

    for (int i = 8; i <= n; i++) {
        int mn = 987654321;
        for (int j = 1; j <= 7; j++) {
            mn = min(mn, dp[i - j] + dp[j]);
        }
        dp[i] += mn;
    }

    cout << dp[n];
    
    return 0;
}