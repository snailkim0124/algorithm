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

int X1, Y1, X2, Y2, X3, Y3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X1 >> Y1;
	cin >> X2 >> Y2;
	cin >> X3 >> Y3;

	int res = (X1 * Y2 + X2 * Y3 + X3 * Y1) - (X2 * Y1 + X3 * Y2 + X1 * Y3);
	
	if (res > 0) cout << "1";
	else if (res < 0) cout << "-1";
	else cout << "0";

	return 0;
}