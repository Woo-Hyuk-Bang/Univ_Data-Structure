#include <stdio.h>
#include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100
typedef char element;		// ��ü!
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// push, pop, stack ����

int is_empty()
{
	return (top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}


// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

// ��ũ �Լ� - ������ ���� ���κ�
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
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
	printf("%d\n", pop()); // ����ϰ� pop�� �����Ͽ�, 4�� ����ϰ� 4�� ���ÿ��� ���ش�.
	printf("%d\n", pop()); // ����ϰ� pop�� �����Ͽ�, 3�� ����ϰ� 3�� ���ÿ��� ���ش�.
	printf("%d\n", pop()); // ����ϰ� pop�� �����Ͽ�, 2�� ����ϰ� 2�� ���ÿ��� ���ش�.
	printf("%d\n", pop()); // ����ϰ� pop�� �����Ͽ�, 1�� ����ϰ� 1�� ���ÿ��� ���ش�.
	printf("%d\n", pop()); // ���������� �Էµ� 1���� �������� ���������Ƿ�, ���� ���
	return 0;
}



// ���� ǥ�� ���� ��� �Լ�
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
			value = ch - '0';	// �Է��� �ǿ������̸�
			push(&s, value);
		}
		else {	//�������̸� �ǿ����ڸ� ���ÿ��� ����
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //������ �����ϰ� ���ÿ� ���� 
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
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}
