#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string x, y;
int dp[1005][1005];
map<char, int> alpha;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	int n = x.size();
	int m = y.size();

	for (int i = 0; i <= n; i++) {
		dp[i][0] = i;
	}

	for (int j = 0; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		int xidx = 0; // 마지막 x 인덱스
		for (int j = 1; j <= m; j++) {
			// 같다면 그대로
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				// 삭제, 삽입, 대체
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
			}

			int yidx = alpha[y[j - 1]];

			// 교환
			if (xidx && yidx) {
				int cost = (i - yidx - 1) + (j - xidx - 1);
				dp[i][j] = min(dp[i][j], dp[yidx - 1][xidx - 1] + cost + 1);
			}

			// 문자가 일치하면 xidx 갱신
			if (x[i - 1] == y[j - 1]) {
				xidx = j;
			}
		}

		// x 문자 위치 기록
		alpha[x[i - 1]] = i;
	}

	cout << dp[n][m] << "\n";
	
	return 0;
}