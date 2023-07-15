#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long int two = 0;
		long long int five = 0;
		long long int cnt = 0;
		cin >> n;
		for (int j = 1; pow(2,j)<=n; j++) {
			two += n / pow(2, j);
		}
		for (int j = 1; pow(5, j) <= n; j++) {
			five += n / pow(5, j);
		}
		cnt = min(two, five);
		cout << cnt << "\n";

	}
	return 0;
}