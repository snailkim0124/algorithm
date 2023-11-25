#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pi 3.141592

double d1, d2;
double sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> d1;
	cin >> d2;

	sum = d1 * 2 + (d2 * 2 * pi);

	cout << fixed;
	cout.precision(6);
	cout << sum;
	
	return 0;
}