#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m;
int arr[5] = { 0, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		swap(arr[x], arr[y]);
	}

	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) {
			cout << i;
			exit(0);
		}
	}
	
	cout << -1;

	return 0;
}