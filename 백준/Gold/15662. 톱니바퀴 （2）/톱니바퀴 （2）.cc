#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
string s[1005];
int k;
int cnt;

void rotate_gear(int a, int b) {
	if (b == 1) rotate(s[a].begin(), s[a].begin() + 1, s[a].begin() + 8);
	else if (b == -1) rotate(s[a].rbegin(), s[a].rbegin() + 1, s[a].rbegin() + 8);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s[i];
	}

	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		// 다른 극이 있는지 찾기
		int left = a;
		for (; left > 1; left--) {
			if (s[left][6] == s[left - 1][2]) break;
		}

		int right = a;
		for (; right < t; right++) {
			if (s[right][2] == s[right + 1][6]) break;
		}
		// cout << left << " : " << right << "\n";

		int tmpb = b;
		for (int i = a; i >= left; i--) {
			if (tmpb == 1) tmpb = -1;
			else if (tmpb == -1) tmpb = 1;
			rotate_gear(i, tmpb);
		}

		tmpb = b;
		for (int i = a + 1; i <= right; i++) {
			rotate_gear(i, tmpb);
			if (tmpb == 1) tmpb = -1;
			else if (tmpb == -1) tmpb = 1;
		}
	}

	for (auto it : s) {
		if (it[0] == '1') cnt++;
	}

	cout << cnt;


	return 0;
}