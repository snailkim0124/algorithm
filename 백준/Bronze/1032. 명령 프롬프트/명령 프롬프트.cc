#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n;
string s[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n == 1) {
		cin >> s[0];
		cout << s[0];
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	char c;

	for (int i = 0; i < s[0].size(); i++) {
		c = s[0][i];
		for (int j = 0; j < n; j++) {
			if (c != s[j][i]) {
				c = '?';
				break;
			}
		}
		cout << c;
	}
	return 0;
}