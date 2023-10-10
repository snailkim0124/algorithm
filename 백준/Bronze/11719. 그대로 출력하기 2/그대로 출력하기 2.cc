#include <bits/stdc++.h>

using namespace std;

string s[105];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 100 && !cin.eof(); i++) {
		getline(cin, s[i]);
		cout << s[i] << "\n";
	}

	

	return 0;
}