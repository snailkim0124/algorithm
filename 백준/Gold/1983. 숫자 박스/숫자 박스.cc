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
vector<int> a, b;
int dp[2][405][405]; // 이전칸 사용유무, a, b
const int INF = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0) a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0) b.push_back(num);
	}

	fill(&dp[0][0][0], &dp[0][0][0] + 2 * 405 * 405, -INF);
	dp[0][0][0] = 0;

	for (int k = 1; k <= n; k++) {
		int now = k % 2;
		int prev = 1 - now;
		// 초기화
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				dp[now][i][j] = -INF;
			}
		}

		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				dp[now][i][j] = max(dp[now][i][j], dp[prev][i][j]);

				// 위쪽만 숫자
				if (i > 0) {
					dp[now][i][j] = max(dp[now][i][j], dp[prev][i - 1][j]);
				}

				// 아래쪽만 숫자
				if (j > 0) {
					dp[now][i][j] = max(dp[now][i][j], dp[prev][i][j - 1]);
				}

				// 둘다
				if (i > 0 && j > 0) {
					dp[now][i][j] = max(dp[now][i][j], dp[prev][i - 1][j - 1] + a[i - 1] * b[j - 1]);
				}
			}
		}
	}
	
	cout << dp[n % 2][a.size()][b.size()] << "\n";
	
	return 0;
}