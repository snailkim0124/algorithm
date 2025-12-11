#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, c, d;
int b[205], dp[205][25005]; // b - k를 최소화하기
int res = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= m; i++) {
		dp[0][i] = abs(b[0] - i);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= c; j++) {
			vector<int> tmp;
			// 후보 집어넣기
			for (int k = j; k <= m; k += c) {
				tmp.push_back(k);
			}

			priority_queue<pii, vector<pii>, greater<pii>> pq;
			int idx = 0;

			for (auto k : tmp) {
				while (idx < tmp.size() && tmp[idx] <= k + d) {
					pq.push({ dp[i - 1][tmp[idx]], tmp[idx] });
					idx++;
				}

				while (!pq.empty() && pq.top().second < k - d) {
					pq.pop();
				}

				dp[i][k] = abs(b[i] - k) + pq.top().first;
			}

		}
	}

	for (int i = 1; i <= m; i++) {
		res = min(res, dp[n - 1][i]);
		// cout << dp[n - 1][i] << " ";
	}
	// cout << "\n";

	cout << n * m - res << "\n";

	return 0;
}