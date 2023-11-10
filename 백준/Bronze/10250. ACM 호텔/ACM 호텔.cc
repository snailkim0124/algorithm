#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &t);
	while (t--) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		if (n % h == 0) {
			printf("%d", h);
		}
		else {
			printf("%d", n % h);
		}
		
		if (n % h == 0) {
			printf("%02d\n", n / h);
		}
		else {
			printf("%02d\n", n / h + 1);
		}
	}
	
	
	return 0;
}