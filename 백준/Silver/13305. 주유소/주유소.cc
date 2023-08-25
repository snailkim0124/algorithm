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
ll meter[100001];
ll price[100001];
ll min_price = 1000000000;
ll res;
ll n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n- 1; i++) {
		cin >> meter[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	min_price = price[0];
	res = min_price * meter[0];

	for (int i = 0; i < n; i++) {
		min_price = min(min_price, price[i + 1]);
		res += min_price * meter[i + 1];
	}
	
	cout << res;

	return 0;
}