#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n;
int arr[10005];
int m;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	sort(arr, arr + n);
	int left = 0;
	int right = arr[n - 1];

	while (left <= right) { // 이분 탐색
		int sum = 0;
		int mid = (left + right) / 2;

		for (int i = 0; i < n; i++) {
			sum += min(arr[i], mid); // 중간값과 arr에 있는 값과 비교해서 최솟값만 더하기
		}

		if (m == sum) {
			res = mid; // m이 sum이랑 같으면 무조건 최대
			break;

		}
		else if (m > sum) { // m이 sum보다 작아도 계속 res받기
			res = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}


	cout << res;

	return 0;
}