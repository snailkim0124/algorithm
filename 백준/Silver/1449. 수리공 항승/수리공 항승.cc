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

int n, l;
int arr[1005];
int cnt = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int sum = 0;
	for(int i = 0 ; i < n-1 ; i++) {
		sum += arr[i + 1] - arr[i];
		if (sum >= l) {
			cnt++;
			sum = 0;
		}
	}

	cout << cnt;
	return 0;
}