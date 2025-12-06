#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
ll res;

bool moum(int idx) {
	return (s[idx] == 'A' || s[idx] == 'E' || s[idx] == 'I' || s[idx] == 'O' || s[idx] == 'U');
}

void go(int idx, int m, int j, bool l, ll sum) {
	if (idx == s.size()) {
		if (l) res += sum;
		return;
	}

	if (s[idx] == '_') {
		if (m < 2) {
			go(idx + 1, m + 1, 0, l, sum * 5);
		}
		if (j < 2) {
			go(idx + 1, 0, j + 1, true, sum); // L 추가
			go(idx + 1, 0, j + 1, l, sum * 20);
		}
	}
	else if (moum(idx)) {
		if (m == 2) return;
		go(idx + 1, m + 1, 0, l, sum);
	}
	else {
		if (j == 2) return;
		if (s[idx] == 'L') go(idx + 1, 0, j + 1, true, sum); // L 추가
		else go(idx + 1, 0, j + 1, l, sum);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	go(0, 0, 0, false, 1);

	cout << res << "\n";

	return 0;
}