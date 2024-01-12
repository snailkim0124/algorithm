#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'E' && s[i + 1] == 'W') cnt++;
	}
	
	cout << cnt;

	return 0;
}