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
ll r[100005];
ll dp[100005];
ll sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r[i];
		sum += r[i];
	}

	if (n == 1) {
		cout << 0 << "\n";
		exit(0);
	}
	else if (n == 2) {
		cout << max(r[0], r[1]) << "\n";
		exit(0);
	}


	dp[0] = r[0];
	dp[1] = r[1];
	dp[2] = r[0] + r[2];

	for (int i = 3; i < n; i++) {
		dp[i] = min(dp[i - 2], dp[i - 3]) + r[i];
	}
	
	cout << sum - min(dp[n - 1], dp[n - 2]) << "\n";


	return 0;
}
