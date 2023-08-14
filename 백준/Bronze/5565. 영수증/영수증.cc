#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;
int a[10];
int sum;
int sum2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> sum;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum2 += a[i];
	}

	cout << sum - sum2;
	
	return 0;
}