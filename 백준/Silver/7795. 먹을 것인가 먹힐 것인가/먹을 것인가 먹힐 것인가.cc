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

int t;
int n, m;
int a[20005], b[20005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		fill(a, a + 20005, 0);
		fill(b, b + 20005, 0);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + m);

		int res = 0;
		for (int i = 0; i < n; i++) {
			auto pos = lower_bound(b, b + m, a[i]); // lower_bound 사용
			res += (int)(pos - &b[0]); // 주소로 빼주기
		}

		cout << res << "\n";
	}
	return 0;
}