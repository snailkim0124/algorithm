#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int arr[10000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 2; j >= i; j--) {
			if (!k) break;
			else {
				swap(arr[j], arr[j + 1]);
				k--;
			}
		}
		if (!k) break;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}