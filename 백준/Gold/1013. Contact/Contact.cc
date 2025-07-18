#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

bool check(string s) {
	regex e("^(100+1+|01)+$");
	return regex_match(s, e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << (check(s) ? "YES" : "NO") << "\n";
	}
	

	return 0;
}