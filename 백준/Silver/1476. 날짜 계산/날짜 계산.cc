#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int e, s, m;
int res = 1;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> e >> s >> m;

	int i = 1, j = 1, k = 1;

	while (1) {
		if (cnt > 7980) break;
		if (i == s && j == m && k == e) {
			cnt++;
			res = cnt;
			break;
		}
		i++;
		j++;
		k++;
		cnt++;
		if (i > 28) i = 1;
		if (j > 19) j = 1;
		if (k > 15) k = 1;
	}

	cout << res;
	return 0;
}