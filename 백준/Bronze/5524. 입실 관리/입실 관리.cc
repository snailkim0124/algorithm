#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			cout << (char)tolower(s[j]);
		}

		cout << "\n";
	}
	
	return 0;
}