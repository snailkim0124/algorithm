#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	string s;
	cin >> s;
	cout << s[0];
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) cout << s[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	
	return 0;
}