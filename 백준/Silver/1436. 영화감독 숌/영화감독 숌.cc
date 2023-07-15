#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int ans = 666;
	n -= 1;
	while (1) {
		if (n == 0) break;
		ans++;
		for (int i = 0; i < 10; i++) {
			if (ans / (int)pow(10, i) % 1000 == 666) {
				n--;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}