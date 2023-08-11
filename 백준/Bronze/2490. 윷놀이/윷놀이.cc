#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 3; i++) {
		int zero = 0;
		for (int j = 0; j < 4; j++) {
			int n;
			cin >> n;
			if (n == 0) zero++;
		}
		if (zero == 0) cout << "E" << "\n";
		else if (zero == 1) cout << "A" << "\n";
		else if (zero == 2) cout << "B" << "\n";
		else if (zero == 3) cout << "C" << "\n";
		else if (zero == 4) cout << "D" << "\n";
	}
	return 0;
}