#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() > 1) {
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		res += a + b;
		pq.push(a + b);
	}

	cout << res;


	return 0;
}