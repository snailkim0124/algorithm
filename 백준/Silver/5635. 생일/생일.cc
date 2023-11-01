#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct list {
	string name;
	int d;
	int m;
	int y;
}LIST;

int n;
LIST person[105];

bool cmp(LIST a, LIST b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			return (a.d < b.d);
		}
		else return (a.m < b.m);
	}
	else return (a.y < b.y);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person[i].name >> person[i].d >> person[i].m >> person[i].y;
	}

	sort(person, person + n, cmp);

	cout << person[n-1].name << "\n" << person[0].name;

	return 0;
}