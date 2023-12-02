#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x, y;
ll res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;

	if (x == y) {
		cout << 0;
		exit(0);
	}

	cout << 2 << "\n";
	res = x * y - x;
	cout << res << "\n";
	res = y - x*y;
	cout << res;



	return 0;
}
