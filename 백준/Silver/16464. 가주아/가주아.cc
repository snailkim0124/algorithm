#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		ll n;
		bool check = true;
		cin >> n;

		for (int i = 1; i <= 32; i++) {
			if (n == (ll)pow(2, i)) {
				check = false;
			}
		}
		if (check) {
			cout << "Gazua\n";
		}
		else {
			cout << "GoHanGang\n";
		}
	}
	return 0;
}