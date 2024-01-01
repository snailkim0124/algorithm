#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
string prime[5] = { "2","3","5","7" };
string number[10] = { "1","2","3","4","5","6","7","8","9" };

bool isprime(string num) {
	int int_num = stoi(num);
	for (int i = 2; i * i <= int_num; i++) {
		if (int_num % i == 0) {
			return 0;
		}
	}
	return 1;
}

void make_prime(string num) {
	if (num.size() == n) {
		cout << num << "\n";
		return;
	}

	for (int i = 0; i < 9; i++) {
		string tmp = num + number[i];
		if (isprime(tmp)) {
			make_prime(tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < 4; i++) {
		make_prime(prime[i]);
	}


	return 0;
}