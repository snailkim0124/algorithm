#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
int mn;
int mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	string tmpa = a;
	string tmpb = b;

	for (int i = 0; i < tmpa.size(); i++) {
		if (tmpa[i] == '5') {
			tmpa[i] = '6';
		}
	}
	
	for (int i = 0; i < tmpb.size(); i++) {
		if (tmpb[i] == '5') {
			tmpb[i] = '6';
		}
	}

	mx = stoi(tmpa) + stoi(tmpb);

	tmpa = a;
	tmpb = b;

	for (int i = 0; i < tmpa.size(); i++) {
		if (tmpa[i] == '6') {
			tmpa[i] = '5';
		}
	}

	for (int i = 0; i < tmpb.size(); i++) {
		if (tmpb[i] == '6') {
			tmpb[i] = '5';
		}
	}

	mn = stoi(tmpa) + stoi(tmpb);

	cout << mn << " " << mx;

	return 0;
}