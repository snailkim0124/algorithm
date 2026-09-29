#include <string>
#include <vector>

using namespace std;

int cnt = 0;

int go(int num, int cnt) {
    if(num == 1) return cnt;
    if(cnt == 500) return -1;
    
    if(num % 2 == 1) return go(num * 3 + 1, cnt + 1);
    else return go(num / 2, cnt + 1);
}

int solution(int num) {
    int answer = 0;
    answer = go(num, 0);
    
    return answer;
}