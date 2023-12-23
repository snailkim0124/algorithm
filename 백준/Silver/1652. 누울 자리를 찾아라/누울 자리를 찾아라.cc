#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
char arr[105][105];
char tmp[105][105];
int garo, sero;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < n; j++) {
			if (j == n - 1) continue;
			if (arr[i][j] == 'X') {
				check = false;
			}
			if (!check && arr[i][j] == '.' && arr[i][j+1] == '.') {
				garo++;
				check = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < n; j++) {
			if (j == n - 1) continue;
			if (arr[j][i] == 'X') {
				check = false;
			}
			if (!check && arr[j][i] == '.' && arr[j+1][i] =='.') {
				sero++;
				check = true;
			}
		}
	}

	cout << garo << " " << sero;

	return 0;
}