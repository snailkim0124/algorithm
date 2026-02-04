#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n, k;
int arr[205];
int dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	fill(&dp[0][0], &dp[0][0] + 205 * 205, INF);

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int sz = 2; sz <= n; sz++) {
		for (int l = 0; l + sz - 1 < n; l++) {
			int r = l + sz - 1;

			// 중간을 기점으로 탐색
			for (int mid = l; mid < r; mid++) {
				int val = dp[l][mid] + dp[mid + 1][r];

				// 양쪽이 다르면 추가
				if (arr[l] != arr[mid + 1]) {
					val++;
				}
				dp[l][r] = min(dp[l][r], val);
			}
		}
	}

	cout << dp[0][n - 1] << "\n";

	return 0;
}