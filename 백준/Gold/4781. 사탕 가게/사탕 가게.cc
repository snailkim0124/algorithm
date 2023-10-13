#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
double m;
int dp[100005];
const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		fill(dp, dp + 100005, 0);
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		int cost = (int)(m * 100 + 0.5);
		for (int i = 0; i < n; i++) {
			int c;
			double p;
			cin >> c >> p;
			int temp = (int)(p * 100 +0.5);
			for (int j = temp; j <= cost; j++) {
				dp[j] = max(dp[j], dp[j - temp] + c);
			}
		}

		cout << dp[cost] << "\n";
	}


	return 0;
}