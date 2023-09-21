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
#include <tuple>

using namespace std;

typedef long long ll;
ll n, m;
ll a[300005];
ll res = 1000000000;

int check(ll mid) {
	ll num = 0;
	for (int i = 0; i < m; i++) {
		num += a[i] / mid;
		if (a[i] % mid != 0) num++;
	}

	return n >= num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);

	ll left = 1;
	ll right = a[m - 1];


	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			res = min(res, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << res;
	
	return 0;
}