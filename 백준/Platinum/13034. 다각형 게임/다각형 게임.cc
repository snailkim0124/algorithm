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
int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 첫 턴에 할 수있는 최선의 수는 반으로 가르는 선택?

	cin >> n;
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		set<int> s;
		
		for (int j = 0; j <= i - 2; j++) {
			s.insert(dp[j] ^ dp[i - 2 - j]); // 대칭되는 값 넣기
		}

		// MEX 값 찾기
		int mex = 0;
		while (s.count(mex)) {
			mex++;
		}
		dp[i] = mex;
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << dp[i] << "\n";
	//}

	if (dp[n]) {
		cout << 1 << "\n";
	}
	else cout << 2 << "\n";

	return 0;
}