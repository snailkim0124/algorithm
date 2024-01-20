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

	string a, b;
	cin >> a >> b;

	a += a; // 연속으로 다음거
	a.pop_back(); // 중복 방지

	vector<int> f = failure(b);

	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		while (j > 0 && a[i] != b[j]) j = f[j - 1];
		if (a[i] == b[j]) j++;
		if (j == b.size()) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}