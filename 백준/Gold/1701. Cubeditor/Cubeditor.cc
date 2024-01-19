#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int res;

vector<int> failure(string& s) {
	vector<int> f(s.size());
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}

	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		string ss = s.substr(i, s.size()); // 부분 문자열
		vector<int> f = failure(ss);

		for (auto it : f) {
			res = max(res, it);
		}
	}

	cout << res;

	return 0;
}