#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, l;
int arr[105][105];
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 가로
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int j;

		for (j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) cnt++;
			else if (arr[i][j] + 1 == arr[i][j + 1] && cnt >= l) cnt = 1; // 오르막길
			else if (arr[i][j] - 1 == arr[i][j + 1] && cnt >= 0) cnt = 1 - l; // 내리막길
			else break;
		}
		if (j == n - 1 && cnt >= 0) res++;
	}

	// 세로
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		int i;

		for (i = 0; i < n - 1; i++) {
			if (arr[i][j] == arr[i + 1][j]) cnt++;
			else if (arr[i][j] + 1 == arr[i + 1][j] && cnt >= l) cnt = 1;
			else if (arr[i][j] - 1 == arr[i + 1][j] && cnt >= 0) cnt = 1 - l;
			else break;
		}
		if (i == n - 1 && cnt >= 0) res++;
	}

	cout << res;
	
	return 0;
}