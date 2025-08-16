#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s[6];
vector<char> v;
vector<int> blanks;
int visited[15];
int cnt;

int Num(char c) {
    return (int)(c - 'A' + 1);
}

bool check() {
    vector<int> checkArr;
    checkArr.push_back(Num(v[0]) + Num(v[2]) + Num(v[5]) + Num(v[7]));
    checkArr.push_back(Num(v[0]) + Num(v[3]) + Num(v[6]) + Num(v[10]));
    checkArr.push_back(Num(v[1]) + Num(v[2]) + Num(v[3]) + Num(v[4]));
    checkArr.push_back(Num(v[7]) + Num(v[8]) + Num(v[9]) + Num(v[10]));
    checkArr.push_back(Num(v[1]) + Num(v[5]) + Num(v[8]) + Num(v[11]));
    checkArr.push_back(Num(v[4]) + Num(v[6]) + Num(v[9]) + Num(v[11]));
    
    for (auto sum : checkArr) {
        if (sum != 26) return false;
    }
    return true;
}

void go(int depth) {
    if (depth == blanks.size()) {
        if (check()) {
            int tmp = 0;
            for (int i = 0; i < 5; i++) {
                for (auto it : s[i]) {
                    if (isalpha(it)) cout << v[tmp++];
                    else cout << it;
                }
                cout << "\n";
            }
            exit(0);
        }
        return;
    }

    int idx = blanks[depth];
    for (int i = 0; i < 12; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v[idx] = (char)('A' + i);
            go(depth + 1);
            v[idx] = 'x';
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> s[i];

        for (auto it : s[i]) {
            if (it == 'x') {
                v.push_back('x');
                blanks.push_back((int)v.size() - 1);
            }
            else if (isalpha(it)) {
                v.push_back(it);
                visited[it - 'A'] = 1;
            }
        }
    }

    go(0);

    return 0;
}