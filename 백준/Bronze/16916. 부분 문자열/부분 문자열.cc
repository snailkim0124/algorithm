#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char s[1000005], p[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	cin >> p;

	if (strstr(s, p) != NULL) {
		cout << 1;
	}
	else cout << 0;


	return 0;
}