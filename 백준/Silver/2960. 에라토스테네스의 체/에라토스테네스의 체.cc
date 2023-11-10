#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int check[1005];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		if (check[i] == 0) {
			k--;
			//cout << i << " ";
			ans = i;
			for (int j = i + i; j <= n; j += i) {
				if (check[j] == 0) {
					//cout << j << " ";
					k--;
					if (k == 0) {
						ans = j;
						break;
					}
				}
				check[j] = 1;
			}
			if (k == 0) {
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
}