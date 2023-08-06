#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int t;
int n;
int dp[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}