#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[10];
int cnt;
char num[15][5][3] = {
	{
		{'*', '*', '*'},
		{'*', ' ', '*'},
		{'*', ' ', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
	},
	
	{
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
	},

	{
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
		{'*', ' ', ' '},
		{'*', '*', '*'},
	},

	{
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
	},
	
	{
		{'*', ' ', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
	},

	{
		{'*', '*', '*'},
		{'*', ' ', ' '},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
	},

	{
		{'*', '*', '*'},
		{'*', ' ', ' '},
		{'*', '*', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
	},

	{
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
		{' ', ' ', '*'},
	},

	{
		{'*', '*', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
	},

	{
		{'*', '*', '*'},
		{'*', ' ', '*'},
		{'*', '*', '*'},
		{' ', ' ', '*'},
		{'*', '*', '*'},
	},
};

string real_num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	
	for (int i = 0; i < 5; i++) {
		getline(cin, s[i]);
	}
	int size = s[0].size();
	if ((size + 1) % 4 != 0) {
		cout << "BOOM!!";
		exit(0);
	}

	for (int j = 0; j < size; j += 4) { // 전체 가로
		bool flag = false;
		for (int l = 0; l < 10; l++) { // 숫자 리스트
			int check = 0;
			for (int i = 0; i < 5; i++) { // 세로
				for (int k = j; k < j + 3; k++) { // 가로
					if (num[l][i][k-j] == s[i][k]) {
						check++;
					}
				}
			}
			if (check == 15) {
				real_num += to_string(l);
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "BOOM!!";
			exit(0);
		}
	}

	if (stoi(real_num) % 6 == 0) {
		cout << "BEER!!";
	}
	else {
		cout << "BOOM!!";
	}

	return 0;
}