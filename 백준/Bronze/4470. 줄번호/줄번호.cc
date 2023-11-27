#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string s[55];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		getline(cin, s[i]);
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ". " << s[i] << "\n";
	}


	return 0;
}