#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <numeric>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

long long int a, b, c;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> a >> b >> c;
	long long res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % c;
		}
		a = ((a % c) * (a % c)) % c;
		b = b / 2;
	}
	
	cout << res;
	return 0;
}