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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n) break;
		string s, t;
		cin >> s >> t;
		int a = 0, b = 0;
		for (auto c : s) {
			if (c == 'a') a++;
			else if (c == 'b') b++;
		}


		int at = 0, bt = 0;
		for (auto c : t) {
			if (c == 'a') at++;
			else if (c == 'b') bt++;
		}

		if (a != at || b != bt) {
			cout << "no\n";
			continue;
		}

		string ans = "";

		while (!s.empty()) {
			if (s.back() == t.back()) {
				s.pop_back();
				t.pop_back();
			}
			else {
				if (t.back() == 'a') {
					// 가장 처음 a, 나중 b
					int aidx = -1;
					int bidx = -1;
					for (int i = 0; i < s.size(); i++) {
						if (aidx == -1 && s[i] == 'a') aidx = i;
						if (aidx != -1 && s[i] == 'b') {
							bidx = i;
							break;
						}
					}

					if (aidx != -1 && bidx != -1) {
						swap(s[aidx], s[bidx]);
					}

					ans += 'A';
				}
				else if (t.back() == 'b') {
					// 가장 처음 b, 나중 a
					int aidx = -1;
					int bidx = -1;
					for (int i = 0; i < s.size(); i++) {
						if (bidx == -1 && s[i] == 'b') bidx = i;
						if (bidx != -1 && s[i] == 'a') {
							aidx = i;
							break;
						}
					}

					if (aidx != -1 && bidx != -1) {
						swap(s[aidx], s[bidx]);
					}

					ans += 'B';
				}
			}
		}

		cout << "yes\n";
		cout << ans << "\n";
	}
	


	return 0;
}