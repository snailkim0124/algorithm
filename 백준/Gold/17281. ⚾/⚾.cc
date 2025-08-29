#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[55][10];
int res;

int baseball(vector<int> order) {
	int nowidx = 0;
	int score = 0;

	for (int i = 0; i < n; i++) {
		// cout << "now_inning : " << i << "\n";

		int base[5] = { 0 };
		int out = 0;

		while (out < 3) {
			int batter = order[nowidx];
			nowidx = (nowidx + 1) % 9;

			if (arr[i][batter] == 0) out++;
			else {
				for (int k = 3; k >= 0; k--) {
					if (base[k] || k == 0) {
						base[k] = 0;
						if (k + arr[i][batter] >= 4) score++;
						else {
							base[k + arr[i][batter]]++;
						}
					}
				}
			}
		}
	}

	return score;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> order = { 0,1,2,3,4,5,6,7,8 };

	do {
		// 1번 선수가 4번 타자인 경우
		if (order[3] != 0) continue;
		res = max(res, baseball(order));
	} while (next_permutation(order.begin(), order.end()));

	cout << res << "\n";

	return 0;
}