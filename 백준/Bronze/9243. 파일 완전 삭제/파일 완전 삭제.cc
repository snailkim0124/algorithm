#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
string a, b;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	
	if (n % 2 == 1) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				cout << "Deletion failed";
				exit(0);
			}
		}
		cout << "Deletion succeeded";
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				cout << "Deletion failed";
				exit(0);
			}
		}
		cout << "Deletion succeeded";
	}

	
	return 0;
}