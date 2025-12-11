#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, k;
ll e[100005], pref[100005], dp[100005];
priority_queue<pll> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> e[i];
		pref[i] = pref[i - 1] + e[i];
	}

	pq.push({ 0, 0 });
	for (int i = 1; i <= n; i++) {
		while (!pq.empty() && pq.top().second < i - k) {
			pq.pop();
		}

		dp[i] = pref[i] + pq.top().first;
		dp[i] = max(dp[i], dp[i - 1]);

		pq.push({ dp[i - 1] - pref[i], i });
	}

	cout << dp[n] << "\n";
	

	return 0;
}