#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a, b;
map<char, int> mp = {
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 }
};

int change_num(string s) {
	int res = 0;
	int idx = 0;
	while (idx < s.size()) {
		if (mp[s[idx]] >= mp[s[idx + 1]]) {
			res += mp[s[idx]];
			idx++;
		}
		else {
			if (idx + 1 >= s.size()) continue;

			string tmp = s.substr(idx, 2);
			// cout << tmp << "\n";

			if (tmp == "IV") res += 4;
			else if (tmp == "IX") res += 9;
			else if (tmp == "XL") res += 40;
			else if (tmp == "XC") res += 90;
			else if (tmp == "CD") res += 400;
			else if (tmp == "CM") res += 900;

			idx += 2;
		}
	}

	return res;
}

string change_rome(int num) {
	string s = to_string(num);
	string res = "";

	// reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {
		if (s.size() - i == 4) {
			int num4 = s[i] - '0';
			for (int j = 0; j < num4; j++) {
				res += "M";
			}
		}
		else if (s.size() - i == 3) {
			int num3 = s[i] - '0';
			if (num3 == 9) {
				res += "CM";
			}
			else if (num3 == 4) {
				res += "CD";
			}
			else if(num3 >= 5){
				res += "D";
				for (int j = 0; j < num3 - 5; j++) {
					res += "C";
				}
			}
			else {
				for (int j = 0; j < num3; j++) {
					res += "C";
				}
			}

		}
		else if (s.size() - i == 2) {
			int num2 = s[i] - '0';
			if (num2 == 9) {
				res += "XC";
			}
			else if (num2 == 4) {
				res += "XL";
			}
			else if (num2 >= 5) {
				res += "L";
				for (int j = 0; j < num2 - 5; j++) {
					res += "X";
				}
			}
			else {
				for (int j = 0; j < num2; j++) {
					res += "X";
				}
			}
		}
		else if (s.size() - i == 1) {
			int num1 = s[i] - '0';
			if (num1 == 9) {
				res += "IX";
			}
			else if (num1 == 4) {
				res += "IV";
			}
			else if (num1 >= 5) {
				res += "V";
				for (int j = 0; j < num1 - 5; j++) {
					res += "I";
				}
			}
			else {
				for (int j = 0; j < num1; j++) {
					res += "I";
				}
			}
		}
	}
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	int anum = change_num(a);
	int bnum = change_num(b);
	int sum = anum + bnum;

	// cout << anum << " : " << bnum;

	cout << sum << "\n";
	cout << change_rome(sum) << "\n";

	return 0;
}