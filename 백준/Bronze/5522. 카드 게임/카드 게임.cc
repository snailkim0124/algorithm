#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define mod 10007

using namespace std;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		sum += num;
	}
	cout << sum;
	return 0;
}