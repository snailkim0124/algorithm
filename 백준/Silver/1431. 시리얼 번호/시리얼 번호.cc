#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;

int n;
string arr[51];

bool cmp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int asum = 0, bsum = 0;
		for (int i = 0; i < a.size(); i++) {
			if (isdigit(a[i])) asum += a[i] - '0';
		}
		for (int i = 0; i < b.size(); i++) {
			if (isdigit(b[i])) bsum += b[i] - '0';
		}
		if (asum == bsum) {
			return a < b;
		}
		else return asum < bsum;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}