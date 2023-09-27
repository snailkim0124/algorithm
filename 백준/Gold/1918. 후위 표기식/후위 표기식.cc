#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#define plus aaa
#define minus bbb

using namespace std;

int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

string expr;
stack<precedence> st;

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];

	switch (*symbol) {
	case'(': return lparen;
	case')': return rparen;
	case'+': return plus;
	case'-': return minus;
	case'/': return divide;
	case'*': return times;
	case'%': return mod;
	case'\0': return eos;
	default: return operand;
	}
}

void printToken(precedence num) {
	switch (num) {
	case plus: cout << "+"; break;
	case minus: cout << "-"; break;
	case times: cout << "*"; break;
	case divide: cout << "/"; break;
	case mod: cout << "%"; break;
	}
	return;
}

void postfix() {
	char symbol; precedence token;
	int n = 0;
	st.push(eos);
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
		if (token == operand) {
			cout << symbol;
		}
		else if (token == rparen) {
			while (st.top() != lparen) {
				printToken(st.top());
				st.pop();
			}
			st.pop();
		}
		else {
			while (isp[st.top()] >= icp[token]) {
				printToken(st.top());
				st.pop();
			}
			st.push(token);
		}
	}
	while ((token = st.top()) != eos) {
		printToken(token);
		st.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> expr;
	postfix();

	return 0;
}