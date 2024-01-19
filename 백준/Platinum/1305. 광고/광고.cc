#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int j = 0;

vector<int> failure(string& s) {
	vector<int> f(s.size());
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}

	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int l;
	string s;
	cin >> l;
	cin >> s;

	vector<int> f = failure(s); // 실패 함수

	cout << l - f[l - 1];

	return 0;
}