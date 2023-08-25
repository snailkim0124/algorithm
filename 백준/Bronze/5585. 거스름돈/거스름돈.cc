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
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	n = 1000 - n;
	cnt += n / 500;
	n %= 500;
	cnt += n / 100;
	n %= 100;
	cnt += n / 50;
	n %= 50;
	cnt += n / 10;
	n %= 10;
	cnt += n / 5;
	n %= 5;
	cnt += n / 1;

	cout << cnt;
	return 0;
}