#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

int n;
double x;
int sum;
int sum2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> x;
	int intx = (int)(x * 100 + 0.5);
	for (int i = 0; i < n - 1; i++) {
		int score;
		string s;
		cin >> score >> s;
		if (s == "A+") {
			sum2 += score * 450;
		}
		else if (s == "A0") {
			sum2 += score * 400;
		}
		else if (s == "B+") {
			sum2 += score * 350;
		}
		else if (s == "B0") {
			sum2 += score * 300;
		}
		else if (s == "C+") {
			sum2 += score * 250;
		}
		else if (s == "C0") {
			sum2 += score * 200;
		}
		else if (s == "D+") {
			sum2 += score * 150;
		}
		else if (s == "D0") {
			sum2 += score * 100;
		}
		else if (s == "F") {
			sum2 += score * 0;
		}
		sum += score;
	}
	int num;
	cin >> num;
	sum += num;
	int tmp = sum2;

	tmp = sum2;
	tmp += num * 0;
	if ((int)((double)tmp / sum) > intx) {
		cout << "F";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 100;

	if ((int)((double)tmp / sum) > intx) {
		cout << "D0";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 150;
	if ((int)((double)tmp / sum) > intx) {
		cout << "D+";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 200;
	if ((int)((double)tmp / sum) > intx) {
		cout << "C0";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 250;
	if ((int)((double)tmp / sum) > intx) {
		cout << "C+";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 300;
	if ((int)((double)tmp / sum) > intx) {
		cout << "B0";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 350;
	if ((int)((double)tmp / sum) > intx) {
		cout << "B+";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 400;
	if ((int)((double)tmp / sum) > intx) {
		cout << "A0";
		exit(0);
	}

	tmp = sum2;
	tmp += num * 450;
	if ((int)((double)tmp / sum) > intx) {
		cout << "A+";
		exit(0);
	}

	cout << "impossible";
	return 0;
}