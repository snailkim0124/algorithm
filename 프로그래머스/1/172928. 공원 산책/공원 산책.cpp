#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

const int dy[4] = {-1,0,1,0}; // 상,우,하,좌
const int dx[4] = {0,1,0,-1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int y = -1, x = -1;
    int n = park.size(); // 세로 길이
    int m = park[0].size(); // 가로 길이
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // 시작점 찾기
            if(park[i][j] == 'S') {
                y = i;
                x = j;
                park[i][j] = 'O';
            }
        }
    }
    
    
    for(int t = 0; t < routes.size(); t++) {
        char cmd = routes[t][0];
        int num = routes[t][2] - '0';
        
        // 다음에 가야하는 곳
        int ny = y;
        int nx = x;
        int dir;
        
        if(cmd == 'N') dir = 0;
        else if(cmd == 'E') dir = 1;
        else if(cmd == 'S') dir = 2;
        else if(cmd == 'W') dir = 3;
        
        bool check = true;
        // 명령어 수행
        for(int k = 0; k < num; k++) {
            ny += dy[dir];
            nx += dx[dir];
            // 조건을 만족하는 경우에는 이동
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || park[ny][nx] == 'X')  {
                check = false;
                break;
            }
        }

        if(check) {
            y = ny; x = nx;
        }
    }
    
    return { y, x };
}