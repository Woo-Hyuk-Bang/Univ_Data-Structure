#include <stdio.h>
#include <stdlib.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100
typedef char element;		// 교체!
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// push, pop, stack 구현

int is_empty()
{
	return (top == -1);
}

// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}


// 삽입 함수
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}

// 삭제 함수
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

// 피크 함수 - 스택의 가장 윗부분
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	push(4);
	printf("%d\n", pop()); // 출력하고 pop을 수행하여, 4를 출력하고 4를 스택에서 없앤다.
	printf("%d\n", pop()); // 출력하고 pop을 수행하여, 3를 출력하고 3을 스택에서 없앤다.
	printf("%d\n", pop()); // 출력하고 pop을 수행하여, 2를 출력하고 2을 스택에서 없앤다.
	printf("%d\n", pop()); // 출력하고 pop을 수행하여, 1를 출력하고 1을 스택에서 없앤다.
	printf("%d\n", pop()); // 마지막으로 입력된 1까지 이전에서 없어졌으므로, 에러 출력
	return 0;
}



// 후위 표기 수식 계산 함수
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';	// 입력이 피연산자이면
			push(&s, value);
		}
		else {	//연산자이면 피연산자를 스택에서 제거
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //연산을 수행하고 스택에 저장 
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void)
{
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}
