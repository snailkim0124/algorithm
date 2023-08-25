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

typedef long long int ll;
ll s;
ll sum, cnt;
ll num = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	while (1) {
		sum += num;
		cnt++;
		if (sum > s) {
			break;
		}
		num++;
	}

	cout << cnt-1;
	return 0;
}