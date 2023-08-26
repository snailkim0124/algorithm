#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int t;
int five, one, ten ,tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	five = t / 300;
	t %= 300;
	one = t / 60;
	t %= 60;
	ten = t / 10;
	t %= 10;
	
	if (t == 0) cout << five << " " << one << " " << ten;
	else cout << -1;



	return 0;
}