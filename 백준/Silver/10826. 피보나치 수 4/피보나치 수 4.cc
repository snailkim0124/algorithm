#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string dp[10005];

string sum_function(string s1, string s2) {
	int sum = 0;
	vector<int> ans, num1, num2;
	string s, tmp;

	if (s1.size() < s2.size()) {
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	num1.push_back(0);
	num2.push_back(0);

	for (int i = 0; i < s1.size() - s2.size(); i++) {
		num2.push_back(0);
	}

	for (int i = 0; i < s1.size(); i++) {
		num1.push_back(s1[i] - '0');
	}

	for (int i = 0; i < s2.size(); i++) {
		num2.push_back(s2[i] - '0');
	}

	for (int i = s1.size(); i > 0; i--) {
		sum = num1[i] + num2[i];
		if (sum >= 10) {
			num1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}

	if (num1.front() != 0) s.push_back('1');

	for (int i = ans.size() - 1; i >= 0; i--) {
		s.push_back(ans[i] + '0');
	}

	num1.clear();
	num2.clear();
	ans.clear();

	return s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	dp[0] = "0";
	dp[1] = "1";

	for (int i = 2; i <= n; i++) {
		dp[i] = sum_function(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n] << "\n";
	return 0;
}