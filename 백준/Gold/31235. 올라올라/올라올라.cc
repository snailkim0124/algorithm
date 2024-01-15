#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[1000005];
int mx;
int res = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n;) {
		mx = 1;
		int tmp = arr[i++];
		while (i < n && tmp > arr[i]) {
			i++;
			mx++;
		}
		res = max(mx, res);
	}

	cout << res;

	return 0;
}