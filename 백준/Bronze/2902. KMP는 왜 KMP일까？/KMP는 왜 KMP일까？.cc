#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) cout << s[i];
	}
	return 0;
}