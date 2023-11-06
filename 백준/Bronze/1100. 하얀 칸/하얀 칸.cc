#include <bits/stdc++.h>
using namespace std;
string s[10];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	

	for (int i = 0; i < 8; i++) {
		cin >> s[i];
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && s[i][j] == 'F') {
					cnt++;
				}
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 1 && s[i][j] == 'F') {
					cnt++;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}