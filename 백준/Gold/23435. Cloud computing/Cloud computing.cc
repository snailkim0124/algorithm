#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<int> arr;
vector<int> v[100005];

char query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	char res;
	cin >> res;
	
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}


	while (arr.size() > 1) {
		vector<int> tmp;

		for (int i = 0; i < arr.size() - 1; i += 2) {
			int a = arr[i];
			int b = arr[i + 1];

			if (query(a, b) == '<') {
				v[a].push_back(b); // 적은 후보들 담기
				tmp.push_back(a);
			}
			else {
				v[b].push_back(a);
				tmp.push_back(b);
			}
		}

		// 홀수 사이즈일 때 부전승
		if (arr.size() % 2 == 1) {
			tmp.push_back(arr.back());
		}

		arr = tmp;
	}

	int mnidx = arr[0]; // 가장 작은 인덱스
	auto mnv = v[mnidx];
	int mn2idx = mnv[0];

	//cout << "mnidx : " << mnidx << "\n";

	for (int i = 1; i < mnv.size(); i++) {
		auto it = mnv[i];

		// 2번째로 작은 인덱스 찾기
		if (query(it, mn2idx) == '<') {
			mn2idx = it;
		}
	}


	cout << "! " << mn2idx << endl;
	

	return 0;
}