#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll t;
ull a = -1, b = -1;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	if (t == 1) {
		cin >> a >> b;
		if (s != "") cout << s << endl;
		else {
			ull sum = a + b;
			s = "aaaaaaaaaaaaa";
			for (int i = 0; i < s.size(); i++) {
				if (!sum) break;
				s[i] = (char)((sum % 26) + 'a');
				sum /= 26;
			}
			cout << s << endl;
		}
	}
	else if (t == 2) {
		cin >> s;
		if(a != -1 && b != -1) cout << a + b << endl;
		else {
			ull res = 0;
			ull k = 1;

			for (int i = 0; i < s.size(); i++) {
				res += (s[i] - 'a') * k;
				k *= 26;
			}

			cout << res << endl;
		}

	}

	return 0;
}