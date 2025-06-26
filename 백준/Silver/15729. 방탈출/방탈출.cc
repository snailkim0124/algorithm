#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[1000005];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			cnt++;
			arr[i] = !arr[i];
			arr[i + 1] = !arr[i + 1];
			arr[i + 2] = !arr[i + 2];
		}
	}

	cout << cnt;

	return 0;
}