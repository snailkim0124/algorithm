#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sum;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		sum += num;
	}

	cout << sum / 60 << "\n";
	cout << sum % 60;
	
	return 0;
}