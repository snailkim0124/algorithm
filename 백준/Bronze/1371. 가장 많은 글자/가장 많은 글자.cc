#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int alpha[27];
string s;
int mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (!cin.eof()) {
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) alpha[s[i] - 'a']++;
		}
	}

	for (int i = 0; i < 26; i++) {
		mx = max(mx, alpha[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == mx) {
			cout << (char)(i + 'a');
		}
	}

	return 0;
}