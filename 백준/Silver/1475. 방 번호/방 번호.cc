#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int number[15];
int mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' == 9) {
			number[6]++;
			continue;
		}
		number[s[i] - '0']++;
	}

	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			mx = max(mx, (number[i]+1) / 2);
			continue;
		}
		mx = max(mx, number[i]);
	}

	cout << mx;

	return 0;
}