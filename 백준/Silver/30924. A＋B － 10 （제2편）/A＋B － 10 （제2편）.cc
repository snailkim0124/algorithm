#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int random_num[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 랜덤함수 이용
	for (int i = 0; i <= 10000; i++) {
		random_num[i] = i + 1;
	}
	random_shuffle(random_num, random_num + 10000);

	int resp, a = 1;
	for (a = 1; a <= 10000; a++) {
		cout << "? A " << random_num[a] << endl;
		cin >> resp;

		if (resp == 1) {
			int b = 1, respb;

			for (b = 1; b <= 10000; b++) {
				cout << "? B " << random_num[b] << endl;
				cin >> respb;

				if (respb == 1) {
					cout << "! " << random_num[a] + random_num[b] << endl;
					exit(0);
				}
			}
		}
	}


	return 0;
}