#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string s;
		getline(cin, s);
		if (cin.eof()) break;
		mp[s]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it : mp) {
		cout << it.first << " " << ((double)it.second / cnt) * 100 << "\n";
	}
	return 0;
}