#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int sum = 0;
	int left = 1;
	int right = 1;

	while (left <= right && right <= n) {
		if (sum < n) {
			sum += right;
			right++;
		}
		
		else if(sum > n) {
			sum -= left;
			left++;
		}
		else {
			cnt++;

			sum += right;
			right++;
		}
	}

	cout << cnt+1;
	
	return 0;
}