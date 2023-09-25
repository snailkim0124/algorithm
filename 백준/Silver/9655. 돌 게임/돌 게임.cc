#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

int n;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (1) {
		if (n == 1) {
			cnt++;
			break;
		}
		else if (n > 3) {
			n -= 3;
			cnt++;
		}
		else {
			n--;
			cnt++;
		}
	}

	if (cnt % 2 == 1) {
		cout << "SK"; // 상근이 먼저
	}
	else {
		cout << "CY"; // 창영이
	}

	return 0;
}