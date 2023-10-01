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

int t;
int alpha[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		fill(alpha, alpha + 27, 0);
		string m;
		cin >> m;
		bool check = false;
		for (int i = 0; i < m.size(); i++) {
			alpha[m[i] - 'A']++;
			if (alpha[m[i] - 'A'] == 3) {
				if (m[i + 1] - 'A' != m[i] - 'A') {
					check = true;
					break;
				}
				else {
					alpha[m[i] - 'A'] = -1;
				}
			}
		}

		if (check) cout << "FAKE" << "\n";
		else cout << "OK" << "\n";
	}
	return 0;
}