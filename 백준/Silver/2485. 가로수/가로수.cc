#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int n, MIN, arr[100005], pref[100005], cnt;

int gcd(int max, int min)
{
	if (min <= 0)
	{
		return max;
	}
	else
	{
		return gcd(min, max % min);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		pref[i] = arr[i + 1] - arr[i];
	}

	MIN = pref[0];
	for (int i = 1; i < n - 1; i++) {
		MIN = gcd(MIN, pref[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		cnt += (pref[i] / MIN) - 1;
	}

	cout << cnt;


	return 0;
}