#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (b - a == c - b) {
			cout << "AP " << c + (b - a) << "\n";
		}
		else {
			cout << "GP " << c * (b / a) << "\n";
		}


	}

	
	return 0;
}