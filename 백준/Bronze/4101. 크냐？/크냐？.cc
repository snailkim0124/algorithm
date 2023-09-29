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
#define plus aaa
#define minus bbb

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a > b) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}