#include <bits/stdc++.h>
using namespace std;

int palin[10000005];
int a, b;

int prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void palindrome() {
	for (int i = 1; i <= 1000; i++) {
		if (i < 10) {
			palin[i]++;
			palin[i * 11]++;
		}
		string temp = to_string(i);
		string temp2 = to_string(i);
		reverse(temp2.begin(), temp2.end());
		string res = temp + temp2;

		if (stoi(res) > 10000000) break;
		palin[stoi(res)]++;
		//cout << res << "\n";

		
		for (int j = 0; j < 10; j++) {
			res.clear();
			res = temp;
			res += (j + '0');
			res += temp2;
			if (stoi(res) > 10000000) continue;
			palin[stoi(res)]++;
			//cout << res << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	palindrome();

	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (i >= 10000000) break;
		if (palin[i]) {
			if (prime(i)) {
				cout << i << "\n";
			}
		}
	}
	cout << -1;
	return 0;
}