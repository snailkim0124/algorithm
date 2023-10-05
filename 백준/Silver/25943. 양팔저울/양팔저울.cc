#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10005];
int sum1;
int sum2;
int res;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sum1 = arr[0];
	sum2 = arr[1];

	for (int i = 2; i < n; i++) {
		if (sum1 == sum2) {
			sum1 += arr[i];
		}
		else if (sum1 > sum2) {
			sum2 += arr[i];
		}
		else {
			sum1 += arr[i];
		}
	}

	res = abs(sum1 - sum2);

	cnt += res / 100;
	res = res % 100;
	cnt += res / 50;
	res = res % 50;
	cnt += res / 20;
	res = res % 20;
	cnt += res / 10;
	res = res % 10;
	cnt += res / 5;
	res = res % 5;
	cnt += res / 2;
	res = res % 2;
	cnt += res;

	cout << cnt;

	return 0;
}