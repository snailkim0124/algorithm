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
ll dp[85];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 피보나치 수 구하기 (75번째 > 1e16)
	dp[1] = dp[2] = 1;
	for (int i = 3; i < 75; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	//cout << dp[75] << "\n";
	//string str = to_string(dp[75]);
	//cout << str.size() << "\n";
	
	cin >> n;
	while (1) {
		ll mx = 0;
		for (int i = 1; i < 75; i++) {
			if (dp[i] <= n) {
				mx = dp[i];
			}
			else break;
		}

		// 피보나치 수에 포함된 경우 그대로 출력
		if (n == mx) {
			cout << n << "\n";
			break;
		}
		
		n -= mx;
	}


	return 0;
}