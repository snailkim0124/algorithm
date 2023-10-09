#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int zero[50];
int one[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		zero[0] = 1; // 초기값 설정
		zero[1] = 0;
		one[0] = 0;
		one[1] = 1;
		for (int i = 2; i <= n; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
			one[i] = one[i - 1] + one[i - 2];
		}
		cout << zero[n] << " " << one[n] << "\n";
	}
	return 0;
}