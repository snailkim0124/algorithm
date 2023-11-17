#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[15];
int pref[15];
int mn = 987654321;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= 10; i++) {
		pref[i] = pref[i - 1] + arr[i];
	}
	

	for (int i = 1; i <= 10; i++) {
		if (mn >= abs(pref[i] - 100)) {
			if (mn == abs(pref[i] - 100)) {
				if (ans < pref[i]) {
					ans = pref[i];
					continue;
				}
			}
			mn = abs(pref[i] - 100);
			ans = pref[i];
		}
	}

	cout << ans;
	return 0;
}