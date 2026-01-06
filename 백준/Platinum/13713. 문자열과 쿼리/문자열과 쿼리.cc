#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> z_func(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	// 접두사 같은지 확인
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			z[i] = min(r - i + 1, z[i - l]);
		}

		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		// 초과 범위
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	int m;
	cin >> s >> m;
	reverse(all(s));

	vector<int> z = z_func(s);

	//for (int i = 0; i < z.size(); i++) {
	//	cout << z[i] << " ";
	//}
	//cout << "\n";

	while (m--) {
		int n;
		cin >> n;

		// cout << "ans : ";
		if (n == s.size()) cout << n << "\n";
		else cout << z[z.size() - n] << "\n";
	}

	return 0;
}