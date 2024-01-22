#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int h, w;
char arr[105][105];
int visited[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int key[27];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cnt = 0;
		memset(key, 0, sizeof(key));
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> arr[i][j];
			}
		}
		string s;
		cin >> s;
		// 초반 열쇠가 있는 경우
		if (s != "0") {
			for (int i = 0; i < s.size(); i++) {
				key[s[i] - 'a']++;
				// cout << "key : " << s[i] << "\n";
			}
		}

		/*cout << "key : ";
		for (int i = 0; i < 26; i++) {
			if (key[i]) cout << (char)(i + 'A') << " ";
		}
		cout << "\n";*/
		
		//for (int i = 0; i < h; i++) {
		//	for (int j = 0; j < w; j++) {
		//		// 시작 위치 넣기
		//		if (i == 0 || i == h - 1 || j == 0 || j == w - 1) { // 가장자리
		//			if (arr[i][j] != '*') {
		//				if (isupper(arr[i][j])) {
		//					if (key[arr[i][j] - 'A']){
		//						q.push({ i, j });
		//						visited[i][j] = 1;
		//					}
		//				}
		//				else {
		//					q.push({ i, j });
		//					visited[i][j] = 1;
		//				}
		//			}
		//		}
		//	}
		//}

		/*while (!q.empty()) {
			int y, x;
			tie(y, x) = q.front();
			q.pop();
			cout << "start : " << y << " : " << x <<  " : " << arr[y][x] << "\n";
		}*/

		queue<pair<int, int>> q;
		queue<pair<int, int>> door[27];
		q.push({ 0, 0 });
		visited[0][0] = 1;
		while (!q.empty()) {
			int y, x;
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nx < 0 || ny < 0 || nx > w + 1 || ny > h + 1 || arr[ny][nx] == '*' || visited[ny][nx]) continue;
				visited[ny][nx] = 1;

				// 문을 만난 경우
				if (isupper(arr[ny][nx])) {
					if (!key[arr[ny][nx] - 'A']) {
						door[arr[ny][nx] - 'A'].push({ ny, nx }); // 다음에 방문
						continue;
					}
					else q.push({ ny, nx }); // 방문
				}
				else {
					// 열쇠를 만난 경우
					if (islower(arr[ny][nx])) {
						key[arr[ny][nx] - 'a']++;
						// 열쇠로 문 열고 다음에 방문
						while (!door[arr[ny][nx] - 'a'].empty()) {
							q.push(door[arr[ny][nx] - 'a'].front());
							door[arr[ny][nx] - 'a'].pop();
						}
					}
					// 문서를 찾은 경우
					else if (arr[ny][nx] == '$') {
						cnt++;
					}
					arr[ny][nx] = '.'; // .으로 바꾸기
					q.push({ ny, nx });
				}

			}
		}
		

		cout << cnt << "\n";

	}
	
	return 0;
}