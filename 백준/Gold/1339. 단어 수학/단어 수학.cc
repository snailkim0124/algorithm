#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n;
int alpha[27];
int sum;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		int pow = 1;
		for (int j = word.size() - 1; j >= 0; j--) {
			alpha[word[j] - 'A'] += pow;
			pow *= 10;
		}
	}
	sort(alpha, alpha + 26, greater<>());

	int cnt = 9;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) break;
		sum += alpha[i] * cnt;
		cnt--;
	}

	cout << sum;
	

	return 0;
}