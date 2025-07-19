#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cube[30];

bool same(int a1, int a2, int a3, int a4) {
	return ((cube[a1] == cube[a2]) && (cube[a2] == cube[a3]) && (cube[a3] == cube[a4]) && (cube[a4] == cube[a1]));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 24; i++) {
		cin >> cube[i];
	}

	// 1. 옆부분
		// 나머지
	if (same(5, 6, 7, 8) && same(21, 22, 23, 24)) {
		// 왼쪽으로 돌림
		if (same(13, 15, 3, 4) && same(1, 2, 17, 19) && same(18, 20, 9, 10) && same(14, 16, 11, 12)) {
			cout << 1 << "\n";
			exit(0);
		}
		// 오른쪽으로 돌림
		else if (same(18, 20, 3, 4) && same(17, 19, 11, 12) && same(9, 10, 13, 15) && same(14, 16, 1, 2)) {
			cout << 1 << "\n";
			exit(0);
		}
	}

	// 2. 세로
		// 나머지
	if (same(13, 14, 15, 16) && same(17, 18, 19, 20)) {
		// 아래로 돌림
		if (same(1, 3, 6, 8) && same(5, 7, 10, 12) && same(9, 11, 21, 23) && same(22, 24, 2, 4)) {
			cout << 1 << "\n";
			exit(0);
		}
		// 위로 돌림
		else if (same(9, 11, 6, 8) && same(5, 7, 2, 4) && same(1, 3, 21, 23) && same(22, 24, 10, 12)) {
			cout << 1 << "\n";
			exit(0);
		}
	}

	// 3. 가로
		// 나머지
	if (same(1, 2, 3, 4) && same(9, 10, 11, 12)) {
		// 오른쪽으로 돌림
		if (same(13, 14, 7, 8) && same(5, 6, 19, 20) && same(17, 18, 23, 24) && same(21, 22, 15, 16)) {
			cout << 1 << "\n";
			exit(0);
		}
		// 왼쪽으로 돌림
		else if (same(5, 6, 15, 16) && same(17, 18, 7, 8) && same(21, 22, 19, 20) && same(13, 14, 23, 24)) {
			cout << 1 << "\n";
			exit(0);
		}
	}
	
	cout << 0 << "\n";
	



	return 0;
}