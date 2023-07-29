#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
int n;
string s;
set<string> st;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "ENTER") {
            cnt += st.size();
            st.clear();
        }
        else {
            st.insert(s);
        }
    }
    cnt += st.size();
    cout << cnt;
    return 0;
}