#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s, t;
vector<int> alpha[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;
	for (int i = 0; i < t.size(); i++) {
		alpha[t[i] - 'a'].push_back(i);
	}

	int res = 0;
	int idx = -1;
	for (auto c : s) {
		if (alpha[c - 'a'].empty()) {
			cout << -1 << "\n";
			exit(0);
		}

		auto it = upper_bound(all(alpha[c - 'a']), idx);

		if (it != alpha[c - 'a'].end()) {
			idx = *it;
		}
		else {
			res++;
			idx = alpha[c - 'a'][0];
		}
	}

	cout << res + 1 << "\n";

	return 0;
}