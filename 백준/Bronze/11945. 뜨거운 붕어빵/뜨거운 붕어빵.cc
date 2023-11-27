#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[15][15];
int res[15][15];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", arr[i][m - 1 - j]);
		}
		printf("\n");
	}


	return 0;
}