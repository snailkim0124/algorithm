#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[1000005];
bool check;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<>());
	
	for (int i = 0; i <= n - 3; i++) {
		if (arr[i] < arr[i + 1] + arr[i + 2]) {
			check = true;
			sum = arr[i] + arr[i + 1] + arr[i + 2];
			break;
		}
	}

	if (check) cout << sum;
	else cout << -1;

	return 0;
}