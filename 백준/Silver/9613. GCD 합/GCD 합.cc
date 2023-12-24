#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int arr[105];

int gcd(int a, int b) {
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		ll sum = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << "\n";

	}
	

	return 0;
}