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
int arr[305];
int dp[305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[0] + arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max({ dp[i], dp[i - 2] + arr[i], arr[i - 1] + arr[i] + dp[i - 3]});
	}

	cout << dp[n - 1] << "\n";

	
	return 0;
}