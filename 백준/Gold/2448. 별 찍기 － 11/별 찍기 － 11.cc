#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char arr[3500][6500];

void printlist(int i, int j, int n) {
	if (n <= 3) { // 별 찍기
		arr[i][j] = '*';						//  *
		arr[i + 1][j - 1] = '*';				// * *
		arr[i + 1][j + 1] = '*';
		for (int k = j - 2; k <= j + 2; k++) {	//*****
			arr[i + 2][k] = '*';
		}
		return;
	}
	printlist(i, j, n / 2);
	printlist(i + n / 2, j - n / 2, n / 2); // 왼쪽부분
	printlist(i + n / 2, j + n / 2, n / 2); // 오른쪽부분

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	fill(&arr[0][0], &arr[0][0] + 3500 * 6500, ' ');
	printlist(1, n, n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	return 0;
}