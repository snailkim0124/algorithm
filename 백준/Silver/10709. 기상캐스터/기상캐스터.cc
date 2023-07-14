#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
int h, w;
int a[104][104];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '.') a[i][j] = -1;
			else a[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 0) {
				int cnt = 1;
				while (a[i][j + 1] == -1) {
					a[i][j + 1] = cnt;
					cnt++;
					j++;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}