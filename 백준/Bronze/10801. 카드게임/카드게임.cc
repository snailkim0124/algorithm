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
int a[15];
int b[15];
int ascore;
int bscore;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 10; i++) {
		cin >> b[i];
	}


	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) ascore++;
		if (b[i] > a[i]) bscore++;
	}

	if (ascore > bscore) cout << "A";
	else if (bscore > ascore) cout << "B";
	else cout << "D";
	return 0;
}
