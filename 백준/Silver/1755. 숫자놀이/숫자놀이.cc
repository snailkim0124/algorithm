#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> v;

bool cmp(int a, int b) {
	string str_a = to_string(a);
	string str_b = to_string(b);

	string alpha_a, alpha_b;

	for (int i = 0; i <= 1; i++) {
		if (str_b.size() == i) continue;

		switch (str_a[i]) {
		case '0':
			alpha_a += "zero ";
			break;
		case '1':
			alpha_a += "one ";
			break;
		case '2':
			alpha_a += "two ";
			break;
		case '3':
			alpha_a += "three ";
			break;
		case '4':
			alpha_a += "four ";
			break;
		case '5':
			alpha_a += "five ";
			break;
		case '6':
			alpha_a += "six ";
			break;
		case '7':
			alpha_a += "seven ";
			break;
		case '8':
			alpha_a += "eight ";
			break;
		case '9':
			alpha_a += "nine ";
			break;
		}
	}

	for (int i = 0; i <= 1; i++) {
		if (str_b.size() == i) continue;
		switch (str_b[i]) {
		case '0':
			alpha_b += "zero ";
			break;
		case '1':
			alpha_b += "one ";
			break;
		case '2':
			alpha_b += "two ";
			break;
		case '3':
			alpha_b += "three ";
			break;
		case '4':
			alpha_b += "four ";
			break;
		case '5':
			alpha_b += "five ";
			break;
		case '6':
			alpha_b += "six ";
			break;
		case '7':
			alpha_b += "seven ";
			break;
		case '8':
			alpha_b += "eight ";
			break;
		case '9':
			alpha_b += "nine ";
			break;
		}
	}

	return alpha_a < alpha_b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		v.push_back(i);
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 0;

	for (auto it : v) {
		cout << it << " ";
		cnt++;
		if (cnt == 10) {
			cnt = 0;
			cout << "\n";
		}
	}


	return 0;
}