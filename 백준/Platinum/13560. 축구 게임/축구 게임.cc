#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[10005];
int sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (sum < i * (i + 1) / 2) {
			cout << -1 << "\n";
			exit(0);
		}
	}

	if (sum != n * (n - 1) / 2) {
		cout << -1 << "\n";
		exit(0);
	}

	cout << 1 << "\n";

	return 0;
}