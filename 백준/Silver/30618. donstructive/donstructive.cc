#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			cout << i << " ";
		}
	}
	for (int i = n; i >= 1; i--) {
		if (i % 2 == 1) {
			cout << i << " ";
		}
	}
	
	return 0;
}