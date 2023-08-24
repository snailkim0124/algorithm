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

int n;
int a[1003002];

int palindrome(int n) {
	string temp = to_string(n);

	int start = 0;
	int end = temp.size() - 1;
	while(start < end) {
		if (temp[start] != temp[end]) {
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i < 1003002; i++) {
		a[i] = i;
	}
	
	for (int i = 2; i * i <= 1003002; i++) {
		if (a[i] != 0) {
			for (int j = i + i; j < 1003002; j += i) {
				a[j] = 0;
			}
		}
	}
	
	int cnt = n;

	while (1) {
		if (a[cnt] != 0) {
			int result = a[cnt];
			if (palindrome(result) == 1) {
				cout << result;
				break;
			}
		}
		cnt++;
	}
	return 0;
}