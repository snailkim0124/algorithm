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
#include <map>

using namespace std;
map<int, int> mp;
int n, m;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		mp[num]++;
	}

	for (int j = 0; j < m; j++) {
		int num;
		cin >> num;
		mp[num]++;
	}

	for (auto it : mp) {
		if (it.second == 1) cnt++;
	}

	cout << cnt;
	return 0;
}