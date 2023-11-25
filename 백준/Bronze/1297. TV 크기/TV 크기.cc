#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d, h, w;
double res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> d >> h >> w;

	res = sqrt((double)(d * d) / (double)(h * h + w * w));
	
	cout << (int)(floor(h * res)) << " " << (int)(floor(w * res));

	return 0;
}