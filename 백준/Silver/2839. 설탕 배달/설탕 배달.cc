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

int n;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	while (1) {
		if (n < 0) break;
		if (n % 5 == 0) {
			cnt += n / 5;
			cout << cnt;
			exit(0);
		}

		n -= 3;
		cnt++;
	}
	cout << -1;
	return 0;
}