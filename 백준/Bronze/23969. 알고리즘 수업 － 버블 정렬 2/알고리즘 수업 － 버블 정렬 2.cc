#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int arr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1] && k) {
				swap(arr[j], arr[j + 1]);
				k--;
			}
			else if (!k) break;
		}
		if (!k) break;
	}

	if (k) cout << -1;
	else {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}

	
	return 0;
}