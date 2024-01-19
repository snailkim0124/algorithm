#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt = 0;
vector<int> v;

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

	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> f = failure(p);

	int j = 0;
	for (int i = 0; i < t.size(); i++) {
		while (j > 0 && t[i] != p[j]) j = f[j - 1];
		if (t[i] == p[j]) j++;
		if (j == p.size()) {
			v.push_back(i - (p.size() - 2));
		}
	}

	cout << v.size() << "\n";
	for (auto it : v) {
		cout << it << " ";
	}

	return 0;
}