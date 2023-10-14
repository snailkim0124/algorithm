#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int Minus[25];
int happy[25];
int dp[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> Minus[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> happy[i];
	}

	for (int i = 0; i < n; i++) {
		int temp = Minus[i];
		for (int j = 100; j > temp; j--) {
			dp[j] = max(dp[j], dp[j - temp] + happy[i]);
		}
	}

	cout << dp[100];

	return 0;
}