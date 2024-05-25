#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n;
bool flag;
int y, x, dir = 1000, d;
// 0 동, 1 북, 2 서, 3 남
string cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	while (n--) {
		cin >> cmd >> d;
		if (cmd == "MOVE") {
			if (dir % 4 == 0) {
				x += d;
			}
			else if (dir % 4 == 1) {
				y -= d;

			}
			else if (dir % 4 == 2) {
				x -= d;

			}
			else if (dir % 4 == 3) {
				y += d;
			}
		}
		else if (cmd == "TURN") {
			if (d == 0) dir--;
			else if (d == 1) dir++;
		}

		if (x < 0 || y < 0 || x > m || y > m) flag = true;
	}

	if (flag) cout << -1;
	else {
		cout << x << " " << y;
	}

	return 0;
}