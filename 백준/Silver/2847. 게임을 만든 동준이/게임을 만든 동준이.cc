#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[105];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		while (arr[i] <= arr[i - 1]) {
			arr[i - 1]--;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}