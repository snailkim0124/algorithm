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

	string s, p;
	cin >> s >> p;
	vector<int> f = failure(p);

	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cout << 1;
			exit(0);
		}
	}

	cout << 0;
	
	return 0;
}