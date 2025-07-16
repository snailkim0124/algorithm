#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int y, m;
		int d = 0;
		cin >> y >> m;
		
		if (m == 1) {
			m = 12;
			y--;
		}
		else if (m == 3) {
			m--;
			// 윤년
			if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0)) d = 29;
			else d = 28;
		}
		else m--;

		switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			d = 31;
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			d = 30;
			break;
		}

		cout << y << " " << m << " " << d << "\n";
	}
	
	
	return 0;
}