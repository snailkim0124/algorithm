#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int minham = 20005;
int mindrink = 20005;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int ham;
		cin >> ham;
		minham = min(minham, ham);
	}

	for (int i = 0; i < 2; i++) {
		int drink;
		cin >> drink;
		mindrink = min(mindrink, drink);
	}

	cout << minham + mindrink - 50;

	return 0;
}