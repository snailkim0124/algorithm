#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Scenario #" << i << ":\n";
		memset(arr, 0, sizeof(arr));
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);

		if (pow(arr[2], 2) == pow(arr[0], 2) + pow(arr[1], 2)) {
			cout << "yes\n\n";
		}
		else cout << "no\n\n";
	}
	

	return 0;
}