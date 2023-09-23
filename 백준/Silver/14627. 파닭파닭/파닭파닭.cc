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
ll s, c;
ll arr[1000005];
ll res;
ll sum;

int check(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < s; i++) {
		cnt += arr[i] / mid;
	}

	return (cnt >= c); // 파닭 수를 넘는지 체크
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	ll left = 1; // 최소
	ll right = 1000000000; // 최대
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << sum - res * c; // 남은 파

	return 0;
}