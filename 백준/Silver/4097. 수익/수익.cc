#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll arr[250005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		ll mx = -987654321;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if (arr[i - 1] > 0) arr[i] += arr[i - 1];
			mx = max(mx, arr[i]);
		}
		
		cout << mx << "\n";
	}


	return 0;
}