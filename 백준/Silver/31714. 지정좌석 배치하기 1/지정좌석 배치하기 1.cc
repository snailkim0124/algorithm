#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, d;
int arr[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			arr[i][j] += (i + 1) * d;
		}
	}

	for (int i = 0; i < n; i++) {
		sort(arr[i], arr[i] + m);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= arr[i + 1][j]) {
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << "YES";

	return 0;
}
