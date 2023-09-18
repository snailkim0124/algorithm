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

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) {
			s[i] = s[i] - 'A' + 'a';
		}
		else {
			s[i] = s[i] - 'a' + 'A';
		}
	}
	
	cout << s;

	return 0;
}