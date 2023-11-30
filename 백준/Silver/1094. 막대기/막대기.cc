#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x;
	for (int i = 0; i <= 6; i++) {
		if (x & (1 << i)) cnt++; // i번째 비트가 켜있으면
	}

	cout << cnt;
	return 0;
}