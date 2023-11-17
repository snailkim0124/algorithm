#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[100005];
int pref[100005];
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + arr[i];
	}

	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l-1] << "\n";
	}

	

	return 0;
}