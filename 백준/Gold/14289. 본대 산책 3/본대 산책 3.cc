#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
ll d;
const ll mod = 1000000007;
// 지도
ll arr[55][55];
ll ans[55][55];

void matrix_multi(ll a[][55], ll b[][55]) {
	ll tmp[55][55] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]); // 행렬 곱
				tmp[i][j] %= mod; // 모듈러
			}
			tmp[i][j] %= mod; // 모듈러
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 0; i < n; i++) {
		ans[i][i] = 1; // 단위행렬
	}

	cin >> d;

	while (d > 0) {
		if (d % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		d /= 2;
	}

	cout << ans[0][0];

	return 0;
}