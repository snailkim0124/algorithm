#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll arr[305][305];
ll rpref[305], cpref[305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			rpref[i] += arr[i][j];
			cpref[j] += arr[i][j];
		}
	}

	ll res = 0;

	// 같은 행
	for (int i = 1; i <= n; i++) {
		ll tmp1 = -1, tmp2 = -1; // 가장 큰거 2개 찾기
		for (int j = 1; j <= n; j++) {
			ll score = cpref[j] - 2 * arr[i][j];
			if (tmp1 < score) {
				tmp2 = tmp1;
				tmp1 = score;
			}
			else if (tmp2 < score) {
				tmp2 = score;
			}
		}
		res = max(res, rpref[i] + tmp1 + tmp2);
	}

	// 같은 열
	for (int j = 1; j <= n; j++) {
		ll tmp1 = -1, tmp2 = -1;
		for (int i = 1; i <= n; i++) {
			ll score = rpref[i] - 2 * arr[i][j];
			if (tmp1 < score) {
				tmp2 = tmp1;
				tmp1 = score;
			}
			else if (tmp2 < score) {
				tmp2 = score;
			}
		}
		res = max(res, cpref[j] + tmp1 + tmp2);
	}

	// 다 다름
	for (int i = 1; i <= n; i++) {
		for (int i2 = i + 1; i2 <= n; i2++) {
			
			ll mx_tmp1 = -1, mx_tmp2 = -1;
			ll mx2_tmp1 = -1, mx2_tmp2 = -1;
			ll idx1 = -1, idx2 = -1;

			for (int j = 1; j <= n; j++) {
				ll score1 = cpref[j] - 2 * arr[i][j] - arr[i2][j];
				ll score2 = cpref[j] - 2 * arr[i2][j] - arr[i][j];

				if (mx_tmp1 < score1) {
					mx_tmp2 = mx_tmp1;
					mx_tmp1 = score1;
					idx1 = j;
				}
				else if (mx_tmp2 < score1) {
					mx_tmp2 = score1;
				}

				if (mx2_tmp1 < score2) {
					mx2_tmp2 = mx2_tmp1;
					mx2_tmp1 = score2;
					idx2 = j;
				}
				else if (mx2_tmp2 < score2) {
					mx2_tmp2 = score2;
				}
			}

			ll sum = 0;
			if (idx1 == idx2) {
				sum = max(mx_tmp1 + mx2_tmp2, mx2_tmp1 + mx_tmp2);
			}
			else {
				sum = mx_tmp1 + mx2_tmp1; // 인덱스가 다르면 가장 베스트
			}


			res = max(res, rpref[i] + rpref[i2] + sum);
		}
	}

	cout << res << "\n";

	return 0;
}