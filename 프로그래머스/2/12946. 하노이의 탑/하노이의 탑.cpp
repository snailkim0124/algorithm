#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int mid, vector<vector<int>>& answer) {
    // 기저 사례
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }

    hanoi(n - 1, from, mid, to, answer);
    answer.push_back({from, to});
    hanoi(n - 1, mid, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, 2, answer);
    return answer;
}