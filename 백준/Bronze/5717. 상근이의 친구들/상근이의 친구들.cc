#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, f;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	while (1) {
		cin >> m >> f;
		if (m == 0 && f == 0)break;
		cout << m + f << "\n";
	}

	return 0;
}