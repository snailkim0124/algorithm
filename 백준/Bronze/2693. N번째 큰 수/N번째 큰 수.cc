#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int arr[15];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 10, greater<>());

		cout << arr[2] << "\n";
	}
	
	return 0;
}