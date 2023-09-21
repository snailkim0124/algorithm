#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <tuple>
#define plus aaa
#define minus bbb
#define div ccc
using namespace std;
int n;
int arr[15];
int MIN = 1000000001;
int MAX = -1000000001;
void counting(int idx, int num, int plus, int minus, int mul, int div) { // 다음 인덱스에 추가하는 방식
	if (idx == n - 1) {
		MIN = min(MIN, num);
		MAX = max(MAX, num);
		return;
	}
	if (plus > 0) counting(idx + 1, num + arr[idx + 1], plus - 1, minus, mul, div); // 더하기
	if (minus > 0) counting(idx + 1, num - arr[idx + 1], plus, minus-1, mul, div); // 빼기
	if (mul > 0) counting(idx + 1, num * arr[idx + 1], plus, minus, mul-1, div); // 곱하기
	if (div > 0) counting(idx + 1, num / arr[idx + 1], plus, minus, mul, div-1); // 나누기
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	counting(0, arr[0], plus, minus, mul, div);
	cout << MAX << "\n" << MIN;
	
	return 0;
}