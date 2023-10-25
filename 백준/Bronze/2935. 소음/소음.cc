#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;
char cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a;
	cin >> cmd;
	cin >> b;

	if (cmd == '*') {
		int zero = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '0') zero++;
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] == '0') zero++;
		}
		cout << 1;
		for (int i = 0; i < zero; i++) {
			cout << 0;
		}
	}
	else if (cmd == '+') {
		if (a.size() > b.size()) {
			for (int i = 0; i < a.size() - b.size(); i++) {
				cout << a[i];
			}
			for (int i = 0; i < b.size(); i++) {
				cout << b[i];
			}
		}
		else if (a.size() < b.size()) {
			for (int i = 0; i < b.size() - a.size(); i++) {
				cout << b[i];
			}
			for (int i = 0; i < a.size(); i++) {
				cout << a[i];
			}
		}
		else {
			cout << 2;
			for (int i = 0; i < a.size() - 1; i++) {
				cout << 0;
			}
		}
	}
	return 0;
}