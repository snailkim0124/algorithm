#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sum[10];
int mx, idx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			int num;
			cin >> num;
			sum[i] += num;
		}
	}

	for (int i = 1; i <= 5; i++) {
		if (sum[i] > mx) {
			mx = sum[i];
			idx = i;
		}
	}

	cout << idx << " " << mx;


	return 0;
}