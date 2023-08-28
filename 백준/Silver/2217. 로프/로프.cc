#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
int arr[100005];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans = max(ans, (n - i) * arr[i]);
	}
	cout << ans;
	return 0;
}