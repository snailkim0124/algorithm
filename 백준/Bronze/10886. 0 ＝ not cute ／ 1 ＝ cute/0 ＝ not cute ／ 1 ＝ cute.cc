#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int zero;
int one;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1) one++;
		else if (num == 0) zero++;
	}
	
	if (one > zero) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";

	return 0;
}