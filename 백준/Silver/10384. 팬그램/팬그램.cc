#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int alpha[26];
string s;
void solve() {
	memset(alpha, 0, sizeof(alpha));
	for (auto it : s) {
		if (isalpha(it)) alpha[tolower(it) - 'a']++;
	}

	int mn = 3;
	for (int i = 0; i < 26; i++) {
		mn = min(mn, alpha[i]);
	}

	if (mn == 0) cout << "Not a pangram\n";
	else if (mn == 1) cout << "Pangram!\n";
	else if (mn == 2) cout << "Double pangram!!\n";
	else if (mn == 3) cout << "Triple pangram!!!\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	cin.ignore();

	for (int T = 1; T <= tt; T++) {
		getline(cin, s);
		cout << "Case " << T << ": ";
		solve();
	}
	
	return 0;
}