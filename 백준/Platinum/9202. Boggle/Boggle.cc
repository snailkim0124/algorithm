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

struct Node {
    bool end, find;
    map<char, Node*> nxt;
    Node() : end(false), find(false) {}
};

struct Trie {
    Node* root;
    Trie() { root = new Node(); }

    void reset() {
        resetNode(root);
    }

    void resetNode(Node* node) {
        node->find = false;
        for (auto& it : node->nxt) {
            resetNode(it.second);
        }
    }

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->nxt[c]) {
                node->nxt[c] = new Node();
            }
            node = node->nxt[c];
        }
        node->end = true;
    }
};

bool cmp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    else return a < b;
}

void dfs(int y, int x, Node* node, string word) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || visited[y][x]) return;
    char c = arr[y][x];
    if (!node->nxt.count(c)) return;

    Node* next = node->nxt[c];
    word.push_back(c);
    visited[y][x] = 1;

    // 최종에 찾은 문자열 없으면 넣기
    if (next->end && !next->find) {
        ans_str.push_back(word);
        next->find = true;
    }

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        dfs(ny, nx, next, word);
    }

    visited[y][x] = 0;
    word.pop_back();
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Trie T;
    cin >> w;
    for (int i = 0; i < w; i++) {
        cin >> s[i];
        T.insert(s[i]);
    }

    cin >> b;
    while (b--) {
        T.reset();
        int mxscore = 0;
        ans_str.clear();
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(i, j, T.root, "");
            }
        }

        sort(all(ans_str), cmp); // 정렬
        for (auto it : ans_str) {
            mxscore += mp_score[it.size()];
        }
        
        cout << mxscore << " " << ans_str[0] << " " << ans_str.size() << "\n";
    }

    return 0;
}