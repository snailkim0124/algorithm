#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
int a, b, cnt;
bool check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	while (1) {
		if (a > b) break;
		else if (a == b) {
			cnt++;
			check = true;
			break;
		}
		string b_str = to_string(b);
		if (b_str[b_str.size() - 1] == '1') {
			b_str.pop_back();
			b = stoi(b_str);
			cnt++;
		}
		else {
			if (b % 2 == 0) {
				b /= 2;
				cnt++;
			}
			else {
				cout << -1;
				exit(0);
			}
		}
	}

	if (check) cout << cnt;
	else cout << -1;

	return 0;
}