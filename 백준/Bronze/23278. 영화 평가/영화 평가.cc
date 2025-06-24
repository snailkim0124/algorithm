#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, l, h;
int arr[55];
double sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < l; i++) {
		sum -= arr[i];
	}

	for (int i = n - 1; i >= n - h; i--) {
		sum -= arr[i];
	}

	cout << fixed;
	cout.precision(9);
	cout << sum / (n - l - h);

	return 0;
}