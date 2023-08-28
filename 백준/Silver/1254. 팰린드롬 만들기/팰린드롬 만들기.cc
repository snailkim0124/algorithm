#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
string s;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> s;
	res = s.size();
	int cnt = 0;
	while (1) {
		bool flag = false;
		for (int i = 0; i < (s.size()-cnt) / 2; i++) {
			if (s[cnt + i] != s[s.size() - 1 - i]) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			cnt++;

		}
		else {
			res += cnt;
			break;
		}
	}
	cout << res;
	return 0;
}