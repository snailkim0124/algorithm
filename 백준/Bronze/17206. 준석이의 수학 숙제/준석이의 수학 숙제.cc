#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
vector<int> ans;
int dp[80005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	dp[10] = 25;
	for (int i = 11; i <= 80000; i++) {
		dp[i] = dp[i - 1];
		if (i % 3 == 0 || i % 7 == 0) {
			dp[i] += i;
		}
	}

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ans.push_back(dp[n]);
	}

	for (auto it : ans) {
		cout << it << " ";
	}
	cout << "\n";

	return 0;
}