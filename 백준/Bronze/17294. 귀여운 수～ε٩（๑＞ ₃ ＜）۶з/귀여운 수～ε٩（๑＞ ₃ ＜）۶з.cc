#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	if (s.size() == 1) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << "\n";
		exit(0);
	}

	ll diff = s[0] - s[1];

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] - s[i + 1] != diff) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << "\n";
			exit(0);
		}
	}

	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << "\n";
	
	return 0;
}