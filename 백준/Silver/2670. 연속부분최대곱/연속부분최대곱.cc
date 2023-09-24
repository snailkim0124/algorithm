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
double arr[10005];
double res = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}

	double tmp = arr[0];
	for (int i = 1; i < n; i++) {
		tmp = max(arr[i], tmp * arr[i]); // 곱했을 때 크면 tmp에 저장
		res = max(tmp, res);
	}

	printf("%.3lf", res);
	return 0;
}