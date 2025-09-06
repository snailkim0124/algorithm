#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

map<char, int> ci_mp; // 문자 -> 숫자
map<int, char> ic_mp; // 숫자 -> 문자
int mod;

string shift_text(string s, int cnt) {
    string res = "";

    for (int i = 0; i < s.size(); i++) {
        res += ic_mp[(ci_mp[s[i]] + cnt) % mod];
    }

    return res;
}

vector<int> failure(string& p) {
    vector<int> f(p.size());
    int j = 0;

    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

int kmp(string& t, string& p) {
    vector<int> f = failure(p);
    vector<int> res;
    int j = 0;

    for (int i = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                res.push_back(i - p.size() + 1);
                j = f[j];
            }
            else j++;
        }
    }

    return res.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        // cout << n << "===================================\n";

        ci_mp.clear();
        ic_mp.clear();
        vector<int> ans;
        string a, w, s;

        cin >> a >> w >> s;
        
        // 순서 설정
        for (int i = 0; i < a.size(); i++) {
            ci_mp[a[i]] = i;
            ic_mp[i] = a[i];
        }

        mod = a.size();
        // 시프트 횟수
        for (int i = 0; i < a.size(); i++) {
            string tmp = shift_text(w, i);
            // cout << tmp << "\n";

            if (kmp(s, tmp) == 1) {
                ans.push_back(i);
            }
        }

        if (ans.empty()) {
            cout << "no solution\n";
        }
        else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << "\n";
        }
        else {
            cout << "ambiguous:";
            for (auto it : ans) {
                cout << " " << it;
            }
            cout << "\n";
        }
    }

    

    return 0;
}