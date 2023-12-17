#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[1005][1005];
int dp[1005][1005];
int mx = 0;

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = min(arr[i-1][j-1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
			}
			mx = max(mx, arr[i][j]);
		}
	}

	printf("%d", mx * mx);

	return 0;
}