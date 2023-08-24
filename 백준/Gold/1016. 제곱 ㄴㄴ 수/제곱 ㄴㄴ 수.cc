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
ll MIN, MAX;
ll check[1003002];
ll cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> MIN >> MAX;

	for (ll i = 2; i * i <= MAX; i++) {
		ll square = i * i;
		ll start = MIN / square;

		if (MIN % square != 0) {
			start++;
		}
		
		for (ll j = start; square *j <= MAX; j++) {
			check[j * square - MIN] = 1;
		}
	}

	for (int i = 0; i <= MAX - MIN; i++) {
		if (check[i] == 0) cnt++;
	}
	cout << cnt;
	return 0;
}