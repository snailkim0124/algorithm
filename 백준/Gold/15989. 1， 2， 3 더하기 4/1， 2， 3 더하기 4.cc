#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
ll t;
ll n;
ll dp[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (j >= i) dp[j] += dp[j - i];
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}