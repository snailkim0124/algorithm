#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
string n;
ll sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	sort(n.begin(), n.end(), greater<>());
	if (n[n.size() - 1] != '0') cout << -1;
	else {
		for (auto it : n) {
			sum += it - '0';
		}

		if (sum % 3 == 0) cout << n;
		else cout << -1;
	}

	

	return 0;
}