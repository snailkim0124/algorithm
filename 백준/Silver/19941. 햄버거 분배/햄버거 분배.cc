#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;

int n, k;
string s;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'P') continue;
		for (int j = i - k; j <= i + k; j++) {
			if (j >= 0 && j < n && s[j] == 'H') {
				s[j] = 'Z';
				cnt++;
				break;
			}
		}
	}
	
	cout << cnt;
	return 0;
}