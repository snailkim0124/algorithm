#include<vector>
#include <queue>
#include <utility>
using namespace std;

int visited[105][105];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps) {
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    fill(&visited[0][0], &visited[0][0] + 105 * 105, 987654321); // visited 배열을 큰 수로 초기화 -> 최단 경로를 찾기 위함
    
    // 0-base
    queue<pair<int, int>> q; // 위치를 담을 큐
    visited[0][0] = 1; // 시작은 이미 방문
    q.push({0, 0});
    
    while(!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        // 도착
        if(y == n - 1 && x == m - 1) {
            return visited[y][x];
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 범위 벗어나면 안됨, 벽이면 안됨
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || maps[ny][nx] == 0) continue;
            
            // 최단으로 갱신 가능하면 넣기
            if(visited[ny][nx] > visited[y][x] + 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx}); // 다음에 갈 곳 큐에 넣기
            }
        }
    }
    
    return -1;
}