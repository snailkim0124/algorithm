#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
string ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - 3 >= 'A') {
			ans += s[i] - 3;
		}
		else {
			ans += s[i] + 23;
		}
	}

	cout << ans;
	return 0;
}