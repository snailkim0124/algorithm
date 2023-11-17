#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[50005];
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		sum += arr[i];
	}


	cout << sum;

	return 0;
}