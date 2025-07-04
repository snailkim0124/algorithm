#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int w;
pii arr[1005];
int dp[1005][1005];
vector<int> police;

int dist(pii& a, pii& b) {
	return abs(a.second - b.second) + abs(a.first - b.first);
}

int go(int police1, int police2) {
	if (police1 == w + 1 || police2 == w + 1) return 0;
	if (dp[police1][police2]) return dp[police1][police2];

	int nxt = max(police1, police2) + 1;
	return dp[police1][police2] = min(go(police1, nxt) + dist(arr[police2], arr[nxt]), go(nxt, police2) + dist(arr[police1], arr[nxt]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> w;

	arr[0] = { 1,1 };
	arr[1] = { n, n };
	for (int i = 2; i <= w + 1; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	cout << go(0, 1) << "\n";

	// 역추적
	int police1 = 0;
	int police2 = 1;
	for (int i = 2; i <= w + 1; i++) {
		if (dp[i][police2] + dist(arr[police1], arr[i]) < dp[police1][i] + dist(arr[police2], arr[i])) {
			cout << 1 << "\n";
			police1 = i;
		}
		else {
			cout << 2 << "\n";
			police2 = i;
		}
	}

	return 0;
}