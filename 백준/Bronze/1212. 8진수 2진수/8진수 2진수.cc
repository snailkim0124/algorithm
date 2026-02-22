#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	if (s == "0") {
		cout << s << "\n";
		exit(0);
	}

	for (int i = 0; i < s.size(); i++) {
		string tmp = "";
		int num = s[i] - '0';
		while (num > 1) {
			tmp += (num % 2 + '0');
			num /= 2;
		}

		if (num == 1) {
			tmp += '1';
		}

		if (i != 0) {
			for (int i = tmp.size(); i < 3; i++) {
				tmp += '0';
			}
		}

		reverse(all(tmp));

		ans += tmp;
	}

	cout << ans << "\n";

	return 0;
}