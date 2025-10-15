#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c;
char arr[755][755];
int mx;
int dp[755][755][2]; // 0 : 좌하단, 1 : 우하단

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '1') {
				dp[i][j][0] = dp[i][j][1] = 1;
				mx = 1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '0') {
				dp[i][j][0] = dp[i][j][1] = 0;
			}
			else {
				if (i + 1 < r && j - 1 >= 0) dp[i + 1][j - 1][0] = dp[i][j][0] + 1;
				if (i + 1 < r && j + 1 < c) dp[i + 1][j + 1][1] = dp[i][j][1] + 1;
			}

		}
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (dp[i][j][0] && dp[i][j][1]) {
				int tmp = min(dp[i][j][0], dp[i][j][1]);

				while (tmp > 1) {
					if (dp[i - tmp + 1][j - tmp + 1][0] >= tmp && dp[i - tmp + 1][j + tmp - 1][1] >= tmp) {
						mx = max(mx, tmp);
					}
					tmp--;
				}
			}
		}
	}

	//cout << "============================\n";
	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		cout << dp[i][j][0] << " : " <<  dp[i][j][1] << "\t";
	//		// cout << min(dp[i][j][0], dp[i][j][1]) << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "============================\n";


	cout << mx << "\n";

	return 0;
}
