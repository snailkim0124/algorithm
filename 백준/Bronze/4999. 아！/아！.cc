#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a;
	cin >> b;
	if (a.size() >= b.size()) {
		cout << "go";
	}
	else cout << "no";
	
	return 0;
}