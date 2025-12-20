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
string s[105];
int alpha[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (auto it : s[0]) {
		alpha[it - 'A']++;
	}

	int res = 0;
	for (int i = 1; i < n; i++) {
		int alpha2[27] = { 0 };

		for (auto it : s[i]) {
			alpha2[it - 'A']++;
		}

		int diff = 0;
		for (int j = 0; j < 26; j++) {
			diff += abs(alpha[j] - alpha2[j]);
		}

		if (s[0].size() == s[i].size()) {
			if (diff == 0 || diff == 2) {
				res++;
			}
		}
		else if (abs((int)s[0].size() - (int)s[i].size()) == 1) {
			if (diff == 1) res++;
		}
	}

	cout << res << "\n";


	return 0;
}