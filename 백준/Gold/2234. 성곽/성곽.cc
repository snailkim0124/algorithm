#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[55][55];
int visited[55][55];
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};
int mx = -1, mx2 = -1;
int cnt = 0;

int bfs(int y, int x) {
  int room_size = 1;
  queue<pii> q;
  q.push({y, x});
  visited[y][x]= 1;
  
  while(!q.empty()) {
    int _y, _x;
    tie(_y, _x) = q.front();
    q.pop();
          
    for(int i = 0; i < 4; i++) {
      int ny = _y + dy[i];
      int nx = _x + dx[i];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[ny][nx]) continue;
      if(arr[_y][_x] & (1 << i)) continue; // 비트 켜져있는지 == 벽이 있는지
      visited[ny][nx] = 1;
      q.push({ny, nx});
      room_size++;
    }
  }
  
  return room_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n;j++) {
        if(!visited[i][j]) {
          mx = max(mx, bfs(i, j));
          cnt++;
        }
      }
    }
    
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n ; j++) {
        for(int k = 0; k < 4; k++) {
          if(arr[i][j] & (1 << k)) {
            memset(visited, 0, sizeof(visited));
            arr[i][j] &= ~(1 << k); // 벽 제거
            mx2 = max(mx2, bfs(i, j));
            arr[i][j] |= (1 << k); // 벽 추가
          }
        }
      }
    }
    
    cout << cnt << "\n";
    cout << mx << "\n";
    cout << mx2 << "\n";
    
    return 0;
}