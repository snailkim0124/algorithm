#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int w;
string s[300005];
char arr[5][5];
int visited[5][5];
int b;
vector<string> ans_str;
map<int, int> mp_score = {
    {1, 0},
    {2, 0},
    {3, 1},
    {4, 1},
    {5, 2},
    {6, 3},
    {7, 5},
    {8, 11},
};

bool cmp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    else return a < b;
}

bool dfs(int y, int x, int idx, string word) {
    if (idx == word.size()) return true;
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || visited[y][x] || arr[y][x] != word[idx]) return false;

    visited[y][x] = 1;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (dfs(ny, nx, idx + 1, word)) {
            visited[y][x] = 0;
            return true;
        }
    }

    visited[y][x] = 0;
    return false;
}

void check(string word) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == word[0] && dfs(i, j, 0, word)) {
                ans_str.push_back(word);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> w;
    for (int i = 0; i < w; i++) {
        cin >> s[i];
    }

    cin >> b;
    while (b--) {
        int mxscore = 0;
        ans_str.clear();
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < w; i++) {
            check(s[i]);
        }

        ans_str.erase(unique(all(ans_str)), ans_str.end()); // 중복 원소 제거
        sort(all(ans_str), cmp); // 정렬
        for (auto it : ans_str) {
            mxscore += mp_score[it.size()];
        }
        
        cout << mxscore << " " << ans_str[0] << " " << ans_str.size() << "\n";
    }

    return 0;
}