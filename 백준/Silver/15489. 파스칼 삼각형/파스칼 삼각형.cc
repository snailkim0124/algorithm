#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll dp[35][35];
ll r, c, w;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	dp[1][1] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	cin >> r >> c >> w;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j <= i; j++) {
			res += dp[r + i][c + j];
		}
	}

	cout << res << "\n";

	//for (int i = 0; i <= 10; i++) {
	//	for (int j = 0; j <= 10; j++) {
	//		cout << dp[i][j] << "\t";
	//	}
	//	cout << "\n";
	//}
	
	

	return 0;
}