#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

double r, res, res2;
double pi = 3.14159265358979;

int main() {
	scanf("%lf", &r);
	res = pi * r * r;
	res2 = r * r * 2;
	printf("%.6lf\n",res);
	printf("%.6lf\n", res2);
	return 0;
}