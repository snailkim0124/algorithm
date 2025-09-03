#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[1005];
int dp[1005];
int mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    

    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        mx = max(mx, dp[i]);
    }

    cout << mx << "\n";
    
    return 0;
}