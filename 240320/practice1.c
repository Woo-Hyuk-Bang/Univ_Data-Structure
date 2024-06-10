/*
240320 ���� �޸� �Ҵ� 2
*/
// MALLOC.C: malloc�� �̿��Ͽ� ���� 10�� ������ �� �ִ� ���� �޸𸮸� 
// �Ҵ��ϰ� free�� �̿��Ͽ� �޸𸮸� �ݳ��Ѵ�. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  studentTag {
	char name[10];	 // ���ڹ迭�� �� �̸�
	int age; 		 // ���̸� ��Ÿ���� ������
	double gpa;  	// ��������� ��Ÿ���� �Ǽ���
} student;

int main(void)
{
	student* s;

	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;
	s->gpa = 4.2;

	printf("%s\t %d\t %f", s->name, s->age, s->gpa); // \t -> tabŰ ����
	free(s);

	return 0;
}
