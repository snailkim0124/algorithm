#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> w >> h;
	double bmi = w / (h * h);

	if (bmi > 25) {
		cout << "Overweight\n";
	}
	else if (bmi >= 18.5) {
		cout << "Normal weight\n";
	}
	else {
		cout << "Underweight\n";
	}

	return 0;
}