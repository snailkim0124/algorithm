#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<tll> v;

bool check(int a, int b, int c) {
	int num[5] = { a, b, c };

	for (auto [q, strike, ball] : v) {
		int a2 = q / 100;
		int b2 = (q % 100) / 10;
		int c2 = q % 10;

		int qnum[5] = { a2, b2, c2 };

		int s = 0, b = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j && num[i] == qnum[j]) s++;
				else if (num[i] == qnum[j]) b++;
			}
		}


		//cout << s << " : " << b << "\n";

		if (s != strike || b != ball) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int q, strike, ball;
		cin >> q >> strike >> ball;
		v.push_back({ q, strike, ball });
	}

	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || k == i) continue;
				if (check(i, j, k)) {
					cnt++;
				}
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}