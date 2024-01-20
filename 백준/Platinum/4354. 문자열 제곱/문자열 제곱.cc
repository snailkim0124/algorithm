#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


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

	while (1) {
		string s;
		cin >> s;
		int n = s.size();
		if (s == ".") break;
		vector<int> f = failure(s); // 실패 함수

		if (n % (n - f[n - 1]) != 0) {// 반복될 수 있는 문자열 최소
			cout << 1 << "\n";
		}
		else cout << n / (n - f[n - 1]) << "\n";

	}

	return 0;
}