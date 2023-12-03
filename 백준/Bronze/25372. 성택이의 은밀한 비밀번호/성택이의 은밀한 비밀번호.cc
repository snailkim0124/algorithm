#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s.size() >= 6 && s.size() <= 9) {
			cout << "yes\n";
		}
		else cout << "no\n";
	}

	return 0;
}
