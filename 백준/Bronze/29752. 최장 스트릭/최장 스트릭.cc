#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>

using namespace std;

int n;
int cnt;
int res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) cnt = 0;
		else {
			cnt++;
			res = max(res, cnt);
		}
	}

	cout << res;
	return 0;
}