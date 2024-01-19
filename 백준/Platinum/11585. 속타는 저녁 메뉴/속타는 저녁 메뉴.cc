#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

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

	int n;
	cin >> n;
	string s, p;

	for (int i = 0; i < n; i++) {
		char num;
		cin >> num;
		s += num;
	}

	for (int i = 0; i < n; i++) {
		char num;
		cin >> num;
		p += num;
	}

	if (s.size() == 1 && s == p) {
		cout << "1/1";
		exit(0);
	}
	
	s += s; // 연속으로 다음거
	s.pop_back(); // 중복방지

	vector<int> f = failure(p);

	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != p[j]) j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == p.size()) {
			cnt++;
		}
	}

	int GCD = gcd(n, cnt);

	cout << cnt / GCD << "/" << n / GCD;

	return 0;
}