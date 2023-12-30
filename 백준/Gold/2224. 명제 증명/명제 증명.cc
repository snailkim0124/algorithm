#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int dist[105][105];
char c;
int cnt;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);
	scanf("%c", &c);
	for (int i = 0; i < n; i++) {
		char p, q;
		scanf("%c", &p);
		scanf("%c", &c);
		scanf("%c", &c);
		scanf("%c", &c);
		scanf("%c", &c);
		scanf("%c", &q);
		scanf("%c", &c);
		//cout << p << " " << q << "\n";
		if (p == q) continue;
		if (!dist[p - 'A'][q - 'A']) {
			dist[p - 'A'][q - 'A'] = 1;
			cnt++;
		}
	}

	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (dist[i][j] || i == j) continue;
				dist[i][j] = (dist[i][k] && dist[k][j]);
				if(dist[i][j]) cnt++;
			}
		}
	}


	printf("%d\n", cnt);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (dist[i][j]) {
				printf("%c => %c\n", i + 'A', j + 'A');
			}
		}
	}

	
	return 0;
}