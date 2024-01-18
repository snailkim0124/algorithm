#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, s, e, t;
const ll mod = 1000003;
// 지도
ll arr[55][55];
ll ans[55][55];

// 가중치 없게 만들기

void matrix_multi(ll a[][55], ll b[][55]) {
	ll tmp[55][55] = { 0 };
	for (int i = 1; i <= n * 5; i++) {
		for (int j = 1; j <= n * 5; j++) {
			tmp[i][j] = 0;
			for (int k = 1; k <= n * 5; k++) {
				tmp[i][j] += (a[i][k] * b[k][j]); // 행렬 곱
				tmp[i][j] %= mod; // 모듈러
			}
			tmp[i][j] %= mod; // 모듈러
		}
	}

	for (int i = 1; i <= n * 5; i++) {
		for (int j = 1; j <= n * 5; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%lld %lld %lld %lld", &n, &s, &e, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ll num;
			scanf("%1lld", &num);
			if (num > 0) {
				arr[i * 5][j * 5 - num + 1] = 1;
			}
		}
		for (int j = 1; j <= 4; j++) {
			arr[(i - 1) * 5 + j][(i-1) * 5 + j + 1] = 1;
		}
	}

	for (int i = 1; i <= 5 * n; i++) {
		ans[i][i] = 1; // 단위행렬
	}

	while (t > 0) {
		if (t % 2 == 1) {
			matrix_multi(ans, arr);
		}
		matrix_multi(arr, arr);
		t /= 2;
	}

	printf("%lld", ans[5 * s][5 * e]);

	return 0;
}