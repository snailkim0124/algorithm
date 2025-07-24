#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	cin >> s;
	while (q--) {
		int cmd, l, r;
		cin >> cmd >> l >> r;
		l--;
		r--;

		if (cmd == 1) {
			int cnt = 1;
			for (int i = l; i <= r - 1; i++) {
				if (s[i] != s[i + 1]) cnt++;
			}
			cout << cnt << "\n";
		}
		else if (cmd == 2) {
			for (int i = l; i <= r; i++) {
				s[i] = (char)(((s[i] - 'A') + 1) % 26) + 'A';
			}
		}
	}

	return 0;
}