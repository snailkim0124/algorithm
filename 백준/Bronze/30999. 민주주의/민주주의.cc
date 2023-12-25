#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
char arr[105];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char num;
		int cnt2 = 0;
		for (int j = 0; j < m; j++) {
			cin >> num;
			if (num == 'O') {
				cnt2++;
			}
		}
		if (cnt2 > m / 2) {
			cnt++;
		}
	}

	cout << cnt;
	



	return 0;
}