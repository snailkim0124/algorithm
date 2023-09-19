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

int n, l;
int idx;
int a;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l; // 물웅덩이 개수, 물웅덩이를 덮을 수 있는 길이
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second; // 웅덩이 시작, 웅덩이 끝
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].second <= idx) continue; // 널판지보다 웅덩이가 작을 때
		idx = max(idx, v[i].first);
		a = (v[i].second - (idx + 1)) / l + 1; // 널판지보다 조금 남은 경우
		res += a;
		idx += a * l;
	}

	cout << res;

	return 0;
}