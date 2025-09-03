#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int dp[1000005];
vector<int> six;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(&dp[0], &dp[0] + 1000005, 987654321);

    int num = 1;
    int d = 5;

    // 육각수 찾기
    while (num < 1000005) {
        six.push_back(num);
        dp[num] = 1;
        num += d;
        d += 4;
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < six.size(); j++) {
            if (i + six[j] <= 1000005) {
                dp[i + six[j]] = min(dp[i] + 1, dp[i + six[j]]);
            }
        }
    }

    cout << dp[n];
    
    return 0;
}