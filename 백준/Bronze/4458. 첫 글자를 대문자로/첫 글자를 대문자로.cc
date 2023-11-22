#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		s[0] = toupper(s[0]);
		cout << s << "\n";
	}
	return 0;
}