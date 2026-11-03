#include <string>
#include <vector>
#include <queue>

using namespace std;

// 사전순으로 빠른 경로 : d -> l -> r -> u
const int dx[4] = {1,0,0,-1}; // 하좌우상
const int dy[4] = {0,-1,1,0};

string res = "";
bool check = false;

void go(int n, int m, int x, int y, int r, int c, int k, int cnt, string tmp) {
    if(check) return; // 이미 찾았으면 종료
    
    int dist = abs(x - r) + abs(y - c); // 목적지까지 최소거리
    int rem = k - cnt; // 남은 이동 횟수
    // 남은 횟수만큼 이동할 수 있어야 하고
    // 왕복으로 이동해야 하기 때문에 짝수여야 함
    if (rem < dist || (rem - dist) % 2 != 0) return;
    
    if(k < cnt) return;
    if(k == cnt) {
        if(x == r && y == c) {
            res = tmp;
            check = true;
            return;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        char cmd;
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        // 범위 벗어나면 안됨
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(i == 0) cmd = 'd';
        else if(i == 1) cmd = 'l';
        else if(i == 2) cmd = 'r';
        else if(i == 3) cmd = 'u';
        
        go(n, m, nx, ny, r, c, k, cnt + 1, tmp + cmd);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    // 0-base
    x--; y--; r--; c--;
    
    go(n, m, x, y, r, c, k, 0, "");
    answer = res;
    
    if(check) return answer;
    else return "impossible";
}