#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int n, res;
int a[100005];
int dp[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	res = a[0];
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		res = max(dp[i], res);
	}

	cout << res;
	return 0;
}