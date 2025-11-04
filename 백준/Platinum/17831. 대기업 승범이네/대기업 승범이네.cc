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
vector<int> adj[200005];
int a[200005];
int dp[200005][2]; // 0 : 시너지 x, 1 : 시너지 o

void dfs(int now, int prev) {
	int sum = 0;
	vector<int> v;

	for (auto next : adj[now]) {
		if (next != prev) {
			dfs(next, now);

			sum += max(dp[next][0], dp[next][1]);

			// 시너지
			int tmp = a[now] * a[next] + dp[next][1] - max(dp[next][0], dp[next][1]);
			v.push_back(tmp);
		}
	}

	dp[now][1] = sum;

	int mx = 0;
	for (auto it : v) {
		mx = max(mx, it);
	}

	dp[now][0] = sum + mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		int num;
		cin >> num;
		adj[num].push_back(i);
		adj[i].push_back(num);
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dfs(1, 0);

	//for (int i = 1; i <= n; i++) {
	//	cout << dp[i][0] << " ";
	//}
	//cout << "\n";
	//for (int i = 1; i <= n; i++) {
	//	cout << dp[i][1] << " ";
	//}
	//cout << "\n";

	cout << max(dp[1][0], dp[1][1]) << "\n";
	


	return 0;
}