#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;

int n, m;
int arr[100005];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (arr[left] + arr[right] >= m) {
			cnt++;
			right--;
			left++;
		}
		else left++;
	}
	
	cout << cnt;
	return 0;
}