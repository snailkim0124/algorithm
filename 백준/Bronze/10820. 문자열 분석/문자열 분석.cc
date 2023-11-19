#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(getline(cin, s)) {
		int alpha = 0;
		int ALPHA = 0;
		int num = 0;
		int space = 0;
		for (int i = 0; i < s.size(); i++) {
			if (isupper(s[i])) ALPHA++;
			if (islower(s[i])) alpha++;
			if (isdigit(s[i])) num++;
			if (isspace(s[i])) space++;
		}

		cout << alpha << " " << ALPHA << " " << num << " " << space << "\n";
	}

	return 0;
}