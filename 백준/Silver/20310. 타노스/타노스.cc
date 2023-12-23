#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int zero, one;
int cntz, cnto;

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

	cntz = zero;
	cnto = one;

	for (int i = 0; i < s.size(); i++) {
		if (cntz != zero / 2) {
			s.erase(s.rfind('0'), 1);
			cntz--;
		}
		if (cnto != one / 2) {
			s.erase(s.find('1'), 1);
			cnto--;
		}
		
	}

	cout << s;

	return 0;
}