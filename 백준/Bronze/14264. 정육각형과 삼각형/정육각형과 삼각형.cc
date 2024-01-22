#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l;
	cout << fixed;
	cout.precision(15);
	cout << (sqrt(3) / 4.0) * (l * l);
	
	return 0;
}