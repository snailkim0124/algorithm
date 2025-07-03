#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[2005];
int dp[2005][2005];

int go(int left, int right, int cnt) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];
	return dp[left][right] = max(arr[left] * cnt + go(left + 1, right, cnt + 1), arr[right] * cnt + go(left, right - 1, cnt + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << go(0, n - 1, 1);

	return 0;
}