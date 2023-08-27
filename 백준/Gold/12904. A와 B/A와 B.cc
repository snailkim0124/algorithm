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
string a, b;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a;
	cin >> b;

	while (1) {
		if (a == b) {
			res = 1;
			break;
		}

		if (a.size() > b.size()) break;

		if (b[b.size() - 1] == 'A') {
			b.pop_back();
		}
		else {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
	}

	cout << res;
	return 0;
}
