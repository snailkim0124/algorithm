#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;
vector<int> a;
bool flag;

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (flag == false) {
			a.push_back(num);
			flag = true;
		}
		else {
			if (a.back() < num) {
				a.push_back(num);
			}
			else {
				*lower_bound(a.begin(), a.end(), num) = num;
			}
		}
	}

	cout << a.size();
	return 0;
}