#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
ll x, y;
ll z;
ll res = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	z = y * 100 / x; // 초기 z

	ll left = 0; // 최소값
	ll right = 1000000000; // 최대값

	while (left <= right) {
		ll mid = (left + right) / 2;
		if ((y + mid) * 100 / (x + mid) > z) { // 이기는 횟수 추가
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << res;

	return 0;
}