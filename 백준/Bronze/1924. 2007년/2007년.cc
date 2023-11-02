#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	int mtod = y;
	if (x - 1 > 0) {
		for (int i = 1; i <= x - 1; i++) {
			switch(i) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					mtod += 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					mtod += 30;
					break;
				default:
					mtod += 28;
			}
		}
	}
	
	switch((mtod - 1) % 7) {
			case 0:
				cout << "MON";
				break;
			case 1:
				cout << "TUE";
				break;
			case 2:
				cout << "WED";
				break;
			case 3:
				cout << "THU";
				break;
			case 4:
				cout << "FRI";
				break;
			case 5:
				cout << "SAT";
				break;
			case 6:
				cout << "SUN";
				break;
	}

	return 0;
}