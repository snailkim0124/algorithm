#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> n;
	string b_str = to_string(b);
	string a_str = to_string(a);
	if ((b_str[0] -'0') % 2 == 0 || (b_str[0] - '0') % 5 == 0) {
		cout << -1;
		exit(0);
	}

	cout << a_str;
	switch (a_str[1]- '0') {
	case 1:
	case 3:
	case 4:
	case 6:
	case 7:
		cout << 1;
		break;
	case 2:
	case 5:
	case 8:
		cout << 3;
		break;
	default:
		cout << 7;
	}
	
	for (int i = 0; i < n - 5; i++) {
		cout << 1;
	}
	cout << b_str;

	return 0;
}