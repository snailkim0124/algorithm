#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000005];
int avg;
int sum1;
int res1;
int res2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum1 += arr[i];
	}
	sort(arr, arr + n);
	avg = sum1 / n;

	for (int i = 0; i < n; i++) {
		if (arr[i] > avg+1) {
			res1 += arr[i] - avg-1;
		}
		else if (arr[i] < avg) {
			res2 += avg - arr[i];
		}
	}

	cout << max(res1, res2);

	return 0;
}