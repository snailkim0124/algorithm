#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int n;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
	return 0;
}