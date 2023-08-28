#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int n, m, res;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> m;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		int cnt = 0;
		if (s[i-1] == 'I') {
			while (s[i] == 'O' && s[i + 1] == 'I') {
				cnt++;
				i += 2;
				if (cnt == n) {
					cnt--;
					res++;
				}
			}
		}
	}

	cout << res;
	return 0;
}