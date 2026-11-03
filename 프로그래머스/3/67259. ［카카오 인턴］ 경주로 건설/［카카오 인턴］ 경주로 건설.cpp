#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

int visited[30][30][4];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int solution(vector<vector<int>> board) {
    int answer = INT_MAX; // 최댓값으로 초기화
    int n = board.size();
    
    queue<tuple<int,int,int>> q;
    
    fill(&visited[0][0][0], &visited[0][0][0] + 30 * 30 * 4, INT_MAX);
    
    for(int i = 0; i < 4; i++) {
        q.push({0, 0, i}); // y좌표, x좌표, 방향
        visited[0][0][i] = 0; // 현재까지의 비용
    }

    
    while(!q.empty()) {
        auto [y, x, dir] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 조건 체크
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 1) continue;
            
            int cost = 0;
            // 방향이 같음 -> 직선 도로 (100원)
            if(dir == i) {
                cost = 100;
            }
            // 방향이 다름 -> 기존 직선 도로(100원) + 코너 (500원)
            else {
                cost = 600;
            }
            
            if(visited[ny][nx][i] > visited[y][x][dir] + cost) {
                visited[ny][nx][i] = visited[y][x][dir] + cost;
                q.push({ny, nx, i});
            }
        }
    }
    
    for(int i = 0; i < 4; i++) {
        answer = min(answer, visited[n - 1][n - 1][i]);
    }
    
    return answer;
}