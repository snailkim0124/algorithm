#include <bits/stdc++.h>

using namespace std;

int t;
int ans;

int ispalindrome(string s, int cnt) {
	int left = 0;
	int right = s.size() - 1;

	while (left <= right) {
		if (s[left] != s[right]) {
			if (cnt == 0) {
				int size = right - left;
				if (!ispalindrome(s.substr(left + 1, size), 1)) return 1;
				else if (!ispalindrome(s.substr(left, size), 1)) return 1;
				else return 2;
			}
			else return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ans = ispalindrome(s, 0);
		cout << ans << "\n";
	}
	return 0;
}