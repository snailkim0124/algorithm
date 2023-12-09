#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int x;
string ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'X') {
			x++;
		}
		else if (s[i] == '.') {
			if (x % 2 == 1) {
				cout << -1;
				exit(0);
			}
			while (x >= 4) {
				ans += "AAAA";
				x -= 4;
			}
			if (x) {
				x -= 2;
				ans += "BB";
			}
			ans += ".";
			x = 0;
		}
	}

	if (x) {
		if (x % 2 == 1) {
			cout << -1;
			exit(0);
		}
		while (x >= 4) {
			ans += "AAAA";
			x -= 4;
		}
		if (x) {
			x -= 2;
			ans += "BB";
		}
	}

	cout << ans;


	return 0;
}