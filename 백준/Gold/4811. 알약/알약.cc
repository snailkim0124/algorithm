#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll dp[35][35];

ll check(int w, int h) {
	if (w == 0 && h == 0) return 1;

	if (dp[w][h]) return dp[w][h];
	ll& res = dp[w][h]; // 계속 누적
	if (w > 0) res += check(w - 1, h + 1);
	if (h > 0) res += check(w, h - 1);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (n == 0) break;
		
		cout << check(n, 0) << "\n";
	}
	return 0;
}