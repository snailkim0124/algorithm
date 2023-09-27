#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

int a, b, c;
int MAX = 0;
int MIN = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;
	MAX = max(max(a, b), c);
	MIN = min(min(a, b), c);

	cout << a + b + c - MAX - MIN;
	return 0;
}