#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
int arr[100005];
int pref[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(pref, 0, sizeof(pref));
		int mx = -987654321;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + arr[i];
		}

		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				mx = max(mx, pref[j] - pref[i]);
			}
		}

		cout << mx << "\n";
	}

	return 0;
}