#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int dy[4] = {-1,0,1,0}; // 상,우,하,좌
const int dx[4] = {0,1,0,-1};
int visited[105][105];
int tmp = 0; // 섬의 숫자의 총합

void dfs(int y, int x, vector<string>& maps) {
    tmp += maps[y][x] - '0';
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || maps[ny][nx] == 'X') continue;
        if(visited[ny][nx]) continue; // 이미 방문한 점은 넘기기
        
        dfs(ny, nx, maps);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].size();
    
    for (int i =0; i < n; i++) {
        for(int j = 0; j < m ; j++) {
            // 방문안한 섬의 첫 부분 찾기
            if(maps[i][j] != 'X' && !visited[i][j]) {
                dfs(i, j, maps);
                answer.push_back(tmp);
                tmp = 0; // tmp 초기화
            }
        }
    }
    
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    if(answer.empty()) return {-1};
    
    return answer;
}