#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int zero, one;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			zero++;
		}
		else if (s[i] == '1') {
			one++;
		}
	}

	for (int i = 0; i < zero / 2; i++) {
		cout << 0;
	}
	for (int i = 0; i < one / 2; i++) {
		cout << 1;
	}

	return 0;
}