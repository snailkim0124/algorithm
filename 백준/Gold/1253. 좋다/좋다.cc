#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, cnt;
int a[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		int ans = a[i];
		int left = 0;
		int right = n - 1;

		while (left < right) {
			if (a[left] + a[right] == ans) {
				if (left != i && right != i) {
					cnt++;
					break;
				}
				else if (left == i) {
					left++;
				}
				else if (right == i) {
					right--;
				}
			}
			else if (a[left] + a[right] < ans) {
				left++;
			}
			else {
				right--;
			}
		}
	}
	
	cout << cnt;

	return 0;
}