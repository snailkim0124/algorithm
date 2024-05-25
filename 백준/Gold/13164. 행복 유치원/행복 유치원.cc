#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int arr[300005];
int pref[300005];
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		pref[i] = arr[i + 1] - arr[i];
	}

	sort(pref, pref + n - 1);

	for (int i = 0; i < n - k; i++) {
		res += pref[i];
	}
	
	cout << res;

	return 0;
}