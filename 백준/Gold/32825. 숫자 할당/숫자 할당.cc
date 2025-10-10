#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int A, B, C, D, E, F, G, H;
int cnt;
int nums[15]; // a , b, c,d,e,f,g,h,i,j,k,l,m
int visited[15];

void check() {
	int ab = E - nums[2] - nums[3];
	int ef = F - nums[6] - nums[7];
	int ae = A - nums[8] - nums[11];
	int bf = B - nums[9] - nums[12];

	if (ab + ef != ae + bf) {
		return;
	}

	vector<int> v;
	for (int i = 1; i <= 13; i++) {
		if (!visited[i]) v.push_back(i);
	}

	if (v.size() != 4) return;

	for (auto a : v) {
		int b = ab - a;
		int e = ae - a;
		int f = ef - e;

		vector<int> tmp = { a,b,e,f };
		sort(all(tmp));

		if (tmp == v) {
			cnt++;
		}
	}
}

void go() {
	// d
	for (nums[3] = 1; nums[3] <= 13; nums[3]++) {
		nums[7] = D - nums[3]; // h
		if (nums[7] < 1 || nums[7] > 13 || nums[7] == nums[3] || visited[nums[7]]) continue;
		visited[nums[3]] = 1;
		visited[nums[7]] = 1;

		// l
		for (nums[11] = 1; nums[11] <= 13; nums[11]++) {
			if (visited[nums[11]]) continue;
			nums[12] = H - nums[11]; // m
			if (nums[12] < 1 || nums[12] > 13 || nums[11] == nums[12] || visited[nums[12]]) continue;
			visited[nums[11]] = 1;
			visited[nums[12]] = 1;
			
			// k
			for (nums[10] = 1; nums[10] <= 13; nums[10]++) {
				if (visited[nums[10]]) continue;
				visited[nums[10]] = 1;
				int cg = C - nums[10];
				int ij = G - nums[10];

				// cg
				for (nums[2] = 1; nums[2] <= 13; nums[2]++) {
					if (visited[nums[2]]) continue;
					nums[6] = cg - nums[2]; // g
					if (nums[6] < 1 || nums[6] > 13 || nums[2] == nums[6] || visited[nums[6]]) continue;
					visited[nums[2]] = 1;
					visited[nums[6]] = 1;

					// ij
					for (nums[8] = 1; nums[8] <= 13; nums[8]++) {
						if (visited[nums[8]]) continue;
						nums[9] = ij - nums[8]; // j
						if (nums[9] < 1 || nums[9] > 13 || nums[8] == nums[9] || visited[nums[9]]) continue;
						visited[nums[8]] = 1;
						visited[nums[9]] = 1;

						check();

						visited[nums[8]] = 0;
						visited[nums[9]] = 0;
					}

					visited[nums[2]] = 0;
					visited[nums[6]] = 0;
				}
				visited[nums[10]] = 0;
			}
			visited[nums[11]] = 0;
			visited[nums[12]] = 0;

		}
		visited[nums[3]] = 0;
		visited[nums[7]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C >> D >> E >> F >> G >> H;
	
	int sum = 91;

	if (A + B + C + D != sum || E + F + G + H != sum) {
		cout << 0 << "\n";
		exit(0);
	}

	go();
	
	cout << cnt << "\n";

	return 0;
}