#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> failure(vector<int>& s) {
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

	int n;
	vector<int> s(720000, 0);
	vector<int> p(360000, 0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s[num] = 1;
		s[num + 360000] = 1; // 연속으로 다음거
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p[num] = 1;
	}

	vector<int> f = failure(p);

	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cout << "possible";
			exit(0);
		}
	}

	cout << "impossible";

	return 0;
}