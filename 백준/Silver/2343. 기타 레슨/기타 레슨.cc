#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <tuple>

using namespace std;

int n, m;
int a[100005];
int MAX;
int sum, res;

int check(int mid) {

	if (MAX > mid) return 0; // 예외 조건
	int tmp = mid;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (mid - a[i] < 0) {
			mid = tmp; // 초기화
			cnt++; // 블루레이++
		}
		mid -= a[i]; // 계속해서 빼주기
	}

	if (mid != tmp) cnt++;
	return cnt <= m; // 블루레이 개수만큼 썼는지 체크
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		MAX = max(MAX, a[i]);
		sum += a[i];
	}

	int left = 0;
	int right = sum;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			res = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << res;
	return 0;
}