#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int n, res, tmp;
int a[100005];
int dp[2][100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	res = a[0];
	dp[0][0] = a[0];
	dp[0][1] = a[0];

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = max(dp[0][i - 1] + a[i], a[i]);
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + a[i]);
		tmp = max(dp[0][i], dp[1][i]);
		res = max(tmp, res);
	}

	cout << res;
	return 0;
}