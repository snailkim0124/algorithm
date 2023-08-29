#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int arr[1000004];
int dp[1000004];
int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        arr[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i] > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                arr[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i] > dp[i / 3] + 1) {
                dp[i] = dp[i / 3] + 1;
                arr[i] = i / 3;
            }
        }
    }

    cout << dp[n] << "\n";
    for (int i = n; i != 1; i = arr[i]) {
        v.push_back(i);
    }
    v.push_back(1);
    for (auto it : v) cout << it << " ";
    return 0;
}