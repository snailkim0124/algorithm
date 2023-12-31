#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[1005];
int n, m;
int cnt;

bool cmp(int a, int b) {
	if (a % 10 == b % 10) {
		return a < b;
	}
	return (a % 10) < (b % 10);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);

	/*for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}*/

	for (int i = 0; i < n; i++) {
		if (m <= 0) break;
		while (arr[i] > 10 && m > 0) {
			arr[i] -= 10;
			cnt++;
			m--;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 10) {
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}