#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cnt += pow((2 * n + 1), 2) + n * (3 * n + 1);
	cout << cnt;

	return 0;
}