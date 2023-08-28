#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
string s,temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	s.push_back('#');
	cin >> temp;
	s += temp;

	for (int i = 1; i < s.size(); i++) {
		cout << s[i];

		if (i % 10 == 0)cout << "\n";
	}
	return 0;
}