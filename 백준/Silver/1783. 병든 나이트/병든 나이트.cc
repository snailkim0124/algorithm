#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) {
		cout << min(4, (m + 1) / 2);
	}
	else if (n >= 3) {
		if (m >= 7) cout << m - 2;
		else cout << min(4, m);
	}
	
	return 0;
}