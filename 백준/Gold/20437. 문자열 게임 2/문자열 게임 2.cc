#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		vector<int> alpha[27];
		string s;
		int k;
		cin >> s;
		cin >> k;

		int mn = INT_MAX, mx = -1;

		for (int i = 0; i < s.size(); i++) {
			alpha[s[i] - 'a'].push_back(i);
		}

		for (int i = 0; i < 26; i++) {
			if (alpha[i].size() < k) continue;

			for (int j = 0; j + k - 1 < alpha[i].size(); j++) {
				int sz = alpha[i][j + k - 1] - alpha[i][j] + 1;

				mn = min(mn, sz);
				mx = max(mx, sz);
			}
		}

		if (mn == INT_MAX || mx == -1) cout << -1 << "\n";
		else cout << mn << " " << mx << "\n";

	}



	return 0;
}