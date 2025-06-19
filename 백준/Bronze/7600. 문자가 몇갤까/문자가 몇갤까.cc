#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int alpha[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (1) {
		int cnt = 0;
		memset(alpha, 0, sizeof(alpha));
		getline(cin, s);

		if (s == "#") break;

		for (auto it : s) {
			if (isalpha(it)) {
				alpha[tolower(it) - 'a']++;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (alpha[i]) cnt++;
		}

		cout << cnt << "\n";
	}



	return 0;
}
