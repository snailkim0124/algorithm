#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 1000
#define MAX_EXPR_SIZE 1000
#define MAX_SIZE 100

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

int top = -1;

void push(precedence item) {
	stack[++top] = item;
}

precedence pop() {
	return stack[top--];
}

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
	case plus: printf("+"); break;
	case minus: printf("-"); break;
	case times: printf("*"); break;
	case divide: printf("/"); break;
	case mod: printf("%%"); break;
	}
	return;
}

void postfix() {
	char symbol; precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
		if (token == operand) {
			printf("%c", symbol);
		}
		else if (token == rparen) {
			while (stack[top] != lparen) {
				printToken(pop());
			}
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token]) {
				printToken(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos) printToken(token);
}

int main() {
	scanf("%s", expr);
	postfix();

	return 0;
}