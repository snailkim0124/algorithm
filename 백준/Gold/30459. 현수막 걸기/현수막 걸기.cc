
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, r;
ll arr[2005];
ll brr[40005];
double res;
ll mx = 0;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%lld %lld %lld", &n, &m, &r);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%lld", &brr[i]);
	}

	sort(arr, arr + n);
	sort(brr, brr + m);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int diff = arr[j] - arr[i];
			int idx = upper_bound(brr, brr + m, (r*2) / diff) - brr - 1;
			if (idx == -1) continue;
			mx = max(mx, diff * brr[idx]);
		}
	}

	if (mx == 0) printf("-1");
	else {
		res = mx;
		printf("%.1lf", (res / 2.0));
	}

	return 0;
}