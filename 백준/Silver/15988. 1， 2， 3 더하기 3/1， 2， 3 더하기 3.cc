#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int t;
int n;
long long int dp[1000004];
long long int mod = 1000000009;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] % mod << "\n";
    }
    return 0;
}