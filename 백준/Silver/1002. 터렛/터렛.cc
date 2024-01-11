#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int diff = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		int rd1 = (r1 - r2) * (r1 - r2);
		int rd2 = (r1 + r2) * (r1 + r2);

		if (diff == 0) {
			if (rd1 == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (diff == rd1) {
			cout << 1 << "\n";
		}
		else if (diff == rd2) {
			cout << 1 << "\n";
		}
		else if (diff > rd1 && diff < rd2) {
			cout << 2 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}