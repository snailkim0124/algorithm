#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[10];
int sum;
int avg;
int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> n;

	while (1) {
		avg = sum / 4;
		if (avg >= n) {
			break;
		}
		sum++;
		cnt++;
	}


	cout << cnt;
	return 0;
}