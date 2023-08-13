#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
long long int n;

int main() {
	scanf("%lld", &n);
	printf("%lld\n", n * (n + 1) / 2);
	printf("%lld\n", (int)pow(n * (n + 1) / 2, 2));
	printf("%lld\n", (int)pow(n * (n + 1) / 2, 2));

	return 0;
}