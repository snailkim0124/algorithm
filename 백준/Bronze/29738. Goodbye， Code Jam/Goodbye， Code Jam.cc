#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	for (int i = 1; i <= t; i++) {

		int res = 0;
		int n;
		cin >> n;
		cout << "Case #" << i << ": ";
		if (n <= 25) {
			cout << "World Finals" << "\n";
		}
		else if (n <= 1000) {
			res = 3;
			cout << "Round " << res << "\n";
		}
		else if (n <= 4500) {
			res = 2;
			cout << "Round " << res << "\n";
		}
		else {
			res = 1;
			cout << "Round " << res << "\n";

		}



	}

	return 0;
}