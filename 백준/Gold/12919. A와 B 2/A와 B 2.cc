#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s, t, rt;

void go(string ans) {
	if (ans == s) {
		cout << 1 << "\n";
		exit(0);
	}
	if (ans.size() < s.size()) {
		// cout << ans << "\n";
		return;
	}

	if (ans[ans.size() - 1] == 'A') {
		string tmp = ans;
		tmp.erase(ans.size() - 1);
		go(tmp);
	}
	if (ans[0] == 'B') {
		string tmp = ans;
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		go(tmp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;

	go(t);

	cout << 0 << "\n";

	return 0;
}