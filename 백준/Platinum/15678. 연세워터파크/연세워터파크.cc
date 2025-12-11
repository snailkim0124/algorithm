#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll INF = 1e16;
ll n, d;
ll k[100005], dp[100005], res = -INF;
priority_queue<pll> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}

	fill(dp, dp + 100005, -INF);

	pq.push({ 0, 0 });
	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top().second < i - d) {
			pq.pop();
		}

		// 1. 새로운 다리 선택 or 2. 이전꺼 이어나감 
		dp[i] = max({ dp[i], k[i], pq.top().first + k[i] });

		pq.push({ dp[i], i});
	}

	for (int i = 0; i < n; i++) {
		// cout << dp[i] << " ";
		res = max(dp[i], res);
	}
	// cout << "\n";

	cout << res << "\n";

	return 0;
}