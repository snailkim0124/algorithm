#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;
ll sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			sum += (a[i] - '0') * (b[j] - '0');
		}
	}

	cout << sum;

	return 0;
}