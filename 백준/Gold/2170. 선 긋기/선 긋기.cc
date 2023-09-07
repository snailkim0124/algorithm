#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
pair<int, int> line[1000005];
int n, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		line[i] = { x, y };
	}

	sort(line, line + n);

	int x = line[0].first;
	int y = line[0].second;

	for (int i = 1; i < n; i++) {
		if (y < line[i].first) {
			res += y - x;
			x = line[i].first;
			y = line[i].second;
		}
		else if (line[i].first <= y && line[i].second >= y) {
			y = line[i].second;
		}
	}
	res += y - x;
	cout << res;
	return 0;
}