#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int arr[10005];
int diff[10005];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 1; i < n; i++) {
		diff[i - 1] = arr[i] - arr[i - 1];
	}

	sort(diff, diff + n);
	for (int i = 0; i < n - k + 1; i++) {
		res += diff[i];
	}
	cout << res;

	return 0;
}