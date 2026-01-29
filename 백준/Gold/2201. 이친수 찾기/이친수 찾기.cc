#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll k;
ll dp[95]; // 최대 90자리

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// 최대 인덱스 찾기
	int idx = 0;
	while (k >= dp[idx]) {
		idx++;
	}

	string ans = "";

	for (int i = idx - 1; i > 1; i--) {
		if (k >= dp[i]) {
			ans += '1';
			k -= dp[i];
		}
		else {
			ans += '0';
		}
	}

	cout << ans << "\n";
	
	return 0;
}