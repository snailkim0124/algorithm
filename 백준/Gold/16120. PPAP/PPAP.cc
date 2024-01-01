#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
string v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		v += s[i];

		if (v.size() < 4) continue;

		while (v.size() >= 4 && v.substr(v.size() - 4, 4) == "PPAP") {
			for (int i = 0; i < 4; i++) {
				v.pop_back();
			}
			v += "P";
		}
	}

	if (v == "P") {
		cout << "PPAP";
	}
	else cout << "NP";

	return 0;
}