#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h> 

using namespace std;
typedef long long ll;
int t;
ll a, b;
ll sum;
bool check[2000001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	check[1] = 1;
	for (int i = 2; i * i < 2000000; i++) {
		if (check[i] == false) {
			for (int j = i * i; j < 2000000; j += i) {
				check[j] = true;
			}
		}
	}

	for (int i = 2; i < 2000001; i++) {
		if (check[i] == false) v.push_back(i);
	}

	cin >> t;
	while (t--) {
		cin >> a >> b;
		sum = a + b;

		if (sum == 2 || sum == 3) {
			cout << "NO" << "\n";
			continue;
		}
		if (sum % 2 == 0) {
			cout << "YES" << "\n";
			continue;
		}

		sum -= 2;
		bool flag = false;
		for (int i = 0; i < v.size() && v[i] * v[i] <= sum; i++) {
			if (sum % v[i] == 0) {
				flag = true;
				break;
			}
		}
		if (flag == false) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
