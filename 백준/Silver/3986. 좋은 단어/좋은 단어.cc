#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <numeric>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
int n;
string word;
int cnt;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word;
		stack<char> stk;
		for (int j = 0; j < word.size(); j++) {
			if (stk.size() && stk.top() == word[j]) {
				stk.pop();
			}
			else
			{
				stk.push(word[j]);
			}
		}
		if (stk.size() == 0) cnt++;
	}
	cout << cnt;

	return 0;
}