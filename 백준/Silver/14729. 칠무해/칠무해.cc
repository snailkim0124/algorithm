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
vector<double> v;
int main() {
	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &grade);
		v.push_back(grade);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 7; i++) {
		printf("%.3lf\n", v[i]);
	}
	return 0;
}