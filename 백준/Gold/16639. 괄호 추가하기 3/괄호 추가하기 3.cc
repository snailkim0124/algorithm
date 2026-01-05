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
string s;
vector<int> num;
vector<char> op;
int min_dp[25][25], max_dp[25][25];

int calc(int a, char c, int b) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}
	
	int nn = num.size();

	fill(&min_dp[0][0], &min_dp[0][0] + 25 * 25, INT_MAX);
	fill(&max_dp[0][0], &max_dp[0][0] + 25 * 25, INT_MIN);

	for (int i = 0; i < nn; i++) {
		min_dp[i][i] = max_dp[i][i] = num[i];
	}

	// 파일 합치기?
	for (int sz = 1; sz < nn; sz++) {
		for (int l = 0; l + sz < nn; l++) {
			int r = l + sz;
			for (int k = l; k < r; k++) {
				int tmp1 = calc(max_dp[l][k], op[k], max_dp[k + 1][r]);
				int tmp2 = calc(max_dp[l][k], op[k], min_dp[k + 1][r]);
				int tmp3 = calc(min_dp[l][k], op[k], max_dp[k + 1][r]);
				int tmp4 = calc(min_dp[l][k], op[k], min_dp[k + 1][r]);

				max_dp[l][r] = max({ max_dp[l][r], tmp1, tmp2, tmp3, tmp4 });
				min_dp[l][r] = min({ min_dp[l][r], tmp1, tmp2, tmp3, tmp4 });
			}
		}
	}

	cout << max_dp[0][nn - 1] << "\n";

	
	return 0;
}