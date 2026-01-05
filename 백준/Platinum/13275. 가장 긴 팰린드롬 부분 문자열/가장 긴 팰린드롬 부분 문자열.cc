#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> manacher(string s) {
	// 문자를 홀수 길이로 만들기
	string t = "#";
	for (char c : s) {
		t += c;
		t += '#';
	}

	int n = t.size();
	vector<int> p(n, 0);

	int c = 0; // 중심
	int r = 0;

	for (int i = 0; i < n; i++) {
		if (i < r) {
			p[i] = min(r - i, p[2 * c - i]);
		}

		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
			p[i]++;
		}

		// 최대 갱신
		if (i + p[i] > r) {
			c = i;
			r = i + p[i];
		}
	}

	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	vector<int> ans = manacher(s);

	int mx = 0;
	for (int i = 0; i < ans.size(); i++) {
		mx = max(mx, ans[i]);
	}

	cout << mx << "\n";

	return 0;
}