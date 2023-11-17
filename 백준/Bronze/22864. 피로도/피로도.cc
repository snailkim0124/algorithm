#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c, m;
int firo;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> m;
	int day = 24;
	while (day) {

		if (firo + a <= m) {
			firo += a;
			res += b;
			day--;
		}
		else {
			firo -= c;
			day--;
		}
		if (firo < 0) firo = 0;
	}


	cout << res;
	

	return 0;
}