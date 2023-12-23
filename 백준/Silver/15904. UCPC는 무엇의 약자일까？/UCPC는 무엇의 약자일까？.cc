#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
string tmp;
bool check;
string res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'U' || s[i] == 'C' || s[i] == 'P') {
			tmp += s[i];
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 'U' && res.empty()) {
			res += 'U';
		}
		else if (tmp[i] == 'C' && res == "U") {
			res += 'C';
		}
		else if (tmp[i] == 'P' && res == "UC") {
			res += 'P';
		}
		else if (tmp[i] == 'C' && res == "UCP") {
			res += 'C';
		}
	}
	
	if (res == "UCPC") cout << "I love UCPC";
	else cout << "I hate UCPC";

	return 0;
}