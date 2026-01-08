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
	cin >> s;

	int n = s.size();
	vector<int> z = z_func(s);
	vector<int> cnt(n + 1, 0);

	for (int i = 1; i < n; i++) {
		cnt[z[i]]++;
	}

	for (int i = n - 1; i >= 1; i--) {
		cnt[i] += cnt[i + 1];
	}

	vector<pii> ans;
	// 두 번이상 등장하기
	for (int i = 1; i <= n; i++) {
		// n일 때는 자기 자신
		if (i == n) {
			ans.push_back({ n, 1 });
			continue;
		}

		// prefix == suffix
		if (z[n - i] == i) {
			ans.push_back({ i, cnt[i] + 1 });
		}
	}

	cout << ans.size() << "\n";
	for (auto [a, b] : ans) {
		cout << a << " " << b << "\n";
	}
	
	return 0;
}