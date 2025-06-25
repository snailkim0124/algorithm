#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int pref[27][200005];
int q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	pref[s[0] - 'a'][0] = 1;
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			pref[j][i] = pref[j][i - 1];
		}
		pref[s[i] - 'a'][i]++;
	}

	cin >> q;
	while (q--) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		cout << pref[c - 'a'][r] - pref[c - 'a'][l - 1] << "\n";
	}
	
	return 0;
}