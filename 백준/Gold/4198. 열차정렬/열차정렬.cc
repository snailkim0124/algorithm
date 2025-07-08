#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int lisarr[2005], ldsarr[2005];
int arr[2005];
int mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		lisarr[i] = 1;
		ldsarr[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				lisarr[i] = max(lisarr[i], lisarr[j] + 1);
			}
			else {
				ldsarr[i] = max(ldsarr[i], ldsarr[j] + 1);
			}
		}
		mx = max(mx, lisarr[i] + ldsarr[i] - 1);
	}

	cout << mx;

	return 0;
}