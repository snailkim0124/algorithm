#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int r, c;
char arr[405][405];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		char arr[405][405] = { 0 };
		int cnt = 0;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'o') {
					// vo^
					if (i - 1 >= 0 && i + 1 <= r) {
						if (arr[i - 1][j] == 'v' && arr[i + 1][j] == '^') {
							cnt++;
						}
					}
					// >o<
					if (j - 1 >= 0 && j + 1 <= c) {
						if (arr[i][j - 1] == '>' && arr[i][j + 1] == '<') {
							cnt++;
						}
					}

				}
			}
		}

		cout << cnt << "\n";

	}
	return 0;
}