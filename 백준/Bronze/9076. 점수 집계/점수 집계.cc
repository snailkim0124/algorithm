#include <bits/stdc++.h>

using namespace std;

int t;
int arr[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < 5; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 5);
		if (arr[3] - arr[1] >= 4) {
			cout << "KIN\n";
		}
		else {
			cout << arr[1] + arr[2] + arr[3] << "\n";
		}

	}
	

	return 0;
}