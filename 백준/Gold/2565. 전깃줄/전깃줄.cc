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

using namespace std;

int n;
int arr[505];
int len;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end()); // a 부분 기준으로 오름차순 정렬

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(arr, arr + len, v[i].second); // LIS 방식 문제
		if (*it == 0) len++;
		*it = v[i].second;
	}

	cout << n - len;
	return 0;
}