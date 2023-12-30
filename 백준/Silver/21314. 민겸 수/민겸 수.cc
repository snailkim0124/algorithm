#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
string max_num, min_num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	int m = 0, k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'M') m++;
		else if(s[i] == 'K') {
			if (m != 0) {
				min_num += '1';
				for (int i = 0; i < m - 1; i++) {
					min_num += '0';
				}
				//min_num += '0' * (m - 1);
				m = 0;
			}
			min_num += '5';
		}
	}
	if (m != 0) {
		min_num += '1';
		for (int i = 0; i < m - 1; i++) {
			min_num += '0';
		}
		//min_num += '0' * (m - 1);
	}

	m = 0; k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'K') {
			max_num += '5';
			if (m != 0) {
				for (int i = 0; i < m; i++) {
					max_num += '0';
				}
				//max_num += '0' * m;
				m = 0;
			}
		}
		else if (s[i] == 'M') {
			m++;
		}
	}
	if (m != 0) {
		//cout << m << "\n";
		for (int i = 0; i < m; i++) {
			max_num += '1';
		}
		//max_num += '1' *  m;
	}


	cout << max_num << "\n" << min_num;

	return 0;
}