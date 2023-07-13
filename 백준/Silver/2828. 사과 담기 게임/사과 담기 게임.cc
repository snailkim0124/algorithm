#include <iostream>
#include <cmath>

using namespace std;
int a[100];
int n, m, j, bas;
int cnt;
int start, num;


int main() {

	cin >> n >> m;
	cin >> j;
	start = 1;

	for (int i = 0; i < j; i++) {
		bas = start + m - 1;
		cin >> num;
		if (num >= start && num <= bas) continue;
		else {
			if (num < start) {
				cnt += start - num;
				start = num;
			}
			else {
				start += num - bas;
				cnt += num - bas;
			}
		}
	}
	cout << cnt;
	return 0;
}