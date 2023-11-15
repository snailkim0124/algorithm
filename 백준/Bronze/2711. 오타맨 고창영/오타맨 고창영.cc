#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < s.size(); i++) {
			if (i == n - 1) continue;
			cout << s[i];
		}

		cout << "\n";
	}

	return 0;
}