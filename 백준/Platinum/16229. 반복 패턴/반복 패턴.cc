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

	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	// 덧붙일 수 있는 개수가 원래문자보다 크면 자기 자신
	if (n <= k) {
		cout << n << "\n";
		exit(0);
	}

	vector<int> z = z_func(s);

	int mx = 0;
	for (int i = 1; i < n; i++) {
		if (i + z[i] == n) {
			int tmp = 0;
			if (n % i != 0) tmp = i - (n % i);// 필요한 부분

			if (tmp <= k) {
				mx = max(mx, i);
			}
		}
	}

	cout << mx << "\n";


	return 0;
}