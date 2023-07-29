#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
int n;
string s1, s2;
set<string> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (s1 == "ChongChong" || st.find(s1) != st.end()) {
            st.insert(s2);
            st.insert("ChongChong");
        }
        if (s2 == "ChongChong" || st.find(s2) != st.end()) {
            st.insert(s1);
            st.insert("ChongChong");
        }
    }

    cout << st.size();
    return 0;
}