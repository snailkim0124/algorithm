#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int i = 666;
	while (1) {
		if (to_string(i).find("666") != string::npos) n--;
		if (n == 0) break;
		i++;
	}
	cout << i << "\n";
	return 0;
}