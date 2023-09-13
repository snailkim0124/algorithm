#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq; // 오름차순
vector<pair<int, int>> v;
int res; // 최대 컵라면 수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y; // 데드라인, 컵라면
		v.push_back({ x,y }); // 처음을 기준으로 정렬
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		res += v[i].second; // 컵라면 더하기
		pq.push(v[i].second);

		if (pq.size() > v[i].first) {
			res -= pq.top(); // 데드라인보다 작으면 컵라면 빼기
			pq.pop();
		}
	}

	cout << res;
	return 0;
}