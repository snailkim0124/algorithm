#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string a, b;
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	for (int i = 0; i <= a.size(); i++) {
		dp[i][0] = i;
	}

	for (int j = 0; j <= b.size(); j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			// 같다면 그대로
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				// 삭제, 삽입, 교체
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
			}
		}
	}

	cout << dp[a.size()][b.size()] << "\n";
	
	return 0;
}