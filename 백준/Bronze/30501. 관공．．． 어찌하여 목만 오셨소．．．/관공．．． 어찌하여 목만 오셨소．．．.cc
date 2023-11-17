#include <bits/stdc++.h>
using namespace std;

int n;
string s[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 'S') {
				flag = true;
				break;
			}
		}

		if (flag) cout << s[i];
	}




	return 0;
}