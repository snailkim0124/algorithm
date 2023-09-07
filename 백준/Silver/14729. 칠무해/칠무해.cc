#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
ll n;
double grade;
priority_queue<double> pq;
vector<double> v;

int main() {
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &grade);
		if (pq.size() == 7) {
			pq.push(grade);
			pq.pop();
		}
		else pq.push(grade);
	}

	while (!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}
	reverse(v.begin(), v.end());

	for (auto it : v) {
		printf("%.3lf\n", it);
	}
	return 0;
}