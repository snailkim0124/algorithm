#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int s;
int visited[2005][2005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;

	queue<tii> q;
	q.push({ 1, 0, 0 });
	visited[1][0] = 1;

	while (!q.empty()) {
		auto [now, clip, cnt] = q.front();
		q.pop();

		if (now == s) {
			cout << cnt << "\n";
			break;
		}

		if (clip != 0) {
			if (!visited[now][now]) {
				q.push({ now, now, cnt + 1 }); // 클립보드 복사
			}
			if (now + clip <= 2000 && !visited[now + clip][clip]) {
				q.push({ now + clip, clip, cnt + 1 }); // 붙여넣기
				visited[now + clip][clip] = 1;
			}
			if (now - 1 >= 0 && !visited[now - 1][clip]) {
				q.push({ now - 1, clip, cnt + 1 }); // 삭제
				visited[now - 1][clip] = 1;
			}
		}
		else {
			if (!visited[now][now]) {
				q.push({ now, now, cnt + 1 }); // 클립보드 복사
			}
			if (now - 1 >= 0 && !visited[now - 1][clip]) {
				q.push({ now - 1, clip, cnt + 1 }); // 삭제
				visited[now - 1][clip] = 1;
			}
		}


	}
	
	return 0;
}