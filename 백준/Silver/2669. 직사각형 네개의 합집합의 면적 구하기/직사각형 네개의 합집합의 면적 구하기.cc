#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int arr[105][105];
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			sum += arr[i][j];
		}
	}

	cout << sum;
	return 0;
}