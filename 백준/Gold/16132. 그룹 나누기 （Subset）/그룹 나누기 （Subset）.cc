#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll dp[2505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	ll sum = n * (n + 1) / 2;

	if (sum % 2 != 0) {
		cout << 0 << "\n";
		exit(0);
	}

	ll tmp = sum / 2;

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = tmp; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}
	
	cout << dp[tmp] / 2 << "\n";

	return 0;
}