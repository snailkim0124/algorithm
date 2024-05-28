#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, l;
int arr[55];
int mn = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	arr[n] = l;

	sort(arr, arr + n + 1);

	int left = 1;
	int right = l - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		// 처음
		int cnt = arr[0] / mid;
		if (arr[0] % mid == 0) cnt--;

		for (int i = 0; i < n; i++) {
			cnt += (arr[i + 1] - arr[i]) / mid; // 휴개소 개수
			
			// 짝수인 경우 1 빼주기
			if ((arr[i + 1] - arr[i]) % mid == 0) {
				cnt--;
			}
		}

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			mn = min(mn, mid);
		}
	}

	cout << mn;

	return 0;
}