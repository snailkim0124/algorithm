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

int t;
int n, m;
int arr[1000005];

int binsearch(int data[], int n, int key) {
    int low, high;
    int mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == data[mid]) {
            return mid;
        }
        else if (key < data[mid]) {
            high = mid - 1;
        }
        else if (key > data[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
        fill(&arr[0], &arr[0] + 1000005, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
        cin >> m;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
            if (binsearch(arr, n, num) == -1) cout << 0 << "\n";
            else cout << 1 << "\n";
		}
	}

	return 0;
}