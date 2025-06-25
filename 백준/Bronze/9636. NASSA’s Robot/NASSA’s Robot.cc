#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		string s;
		int x = 0, y = 0;
		int q = 0;
		cin >> s;
		for (auto it : s) {
			if (it == 'U') y++;
			else if (it == 'R') x++;
			else if (it == 'D') y--;
			else if (it == 'L') x--;
			else if (it == '?') q++;
		}

		cout << x - q << " " << y - q << " ";
		cout << x + q << " " << y + q << "\n";

	}

	return 0;
}