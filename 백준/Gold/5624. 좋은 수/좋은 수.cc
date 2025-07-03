#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[5005];
int dp[400005];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[arr[i] - arr[j] + 200000]) {
				cnt++;
				break;
			}
		}

		for (int j = 0; j <= i; j++) {
			dp[arr[i] + arr[j] + 200000] = 1;
		}
	}

	cout << cnt;

	return 0;
}