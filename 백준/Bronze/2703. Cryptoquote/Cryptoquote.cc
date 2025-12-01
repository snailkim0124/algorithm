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
map<char, char> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	cin.ignore();
	while (t--) {
		mp.clear();
		string s, a;
		getline(cin, s);
		getline(cin, a);

		for (int i = 0; i < a.size(); i++) {
			mp[(char)(i + 'A')] = a[i];
		}

		string ans = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') ans += s[i];
			else ans += mp[s[i]];
		}

		cout << ans << "\n";
	}
	
	return 0;
}