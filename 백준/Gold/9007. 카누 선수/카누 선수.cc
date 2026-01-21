#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k, n;
int arr[4][1005];

void solve() {
	cin >> k >> n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> lv, rv;

	// 1,2번 묶기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[0][i] + arr[1][j];
			lv.push_back(sum);
		}
	}

	// 3,4번 묶기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[2][i] + arr[3][j];
			rv.push_back(sum);
		}
	}

	sort(all(lv));
	sort(all(rv));

	int res = 987654321;
	int mnd = 987654321;

	for (auto a : lv) {
		int need = k - a;
		auto it = lower_bound(all(rv), need);

		// need보다 큰값
		if (it != rv.end()) {
			int sum = a + *it;
			int diff = abs(k - sum);

			if (mnd > diff) {
				mnd = diff;
				res = sum;
			}
			else if (mnd == diff) {
				// 차이가 같은 경우 더 작은 값
				res = min(res, sum);
			}
		}

		// need보다 작은값
		if (it != rv.begin()) {
			int sum = a + *(it - 1);
			int diff = abs(k - sum);

			if (mnd > diff) {
				mnd = diff;
				res = sum;
			}
			else if (mnd == diff) {
				// 차이가 같은 경우 더 작은 값
				res = min(res, sum);
			}
		}
	}

	cout << res << "\n";

	memset(arr, 0, sizeof(arr));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}