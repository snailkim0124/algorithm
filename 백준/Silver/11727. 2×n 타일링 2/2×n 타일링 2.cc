#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define mod 10007

using namespace std;
int n;
int a[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= n; i++) {
		a[i] = (a[i - 1] + 2*a[i - 2]) % mod;
	}
	cout << a[n];
	return 0;
}