/*
240320 동적 메모리 할당 2
*/
// MALLOC.C: malloc을 이용하여 정수 10를 저장할 수 있는 동적 메모리를 
// 할당하고 free를 이용하여 메모리를 반납한다. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  studentTag {
	char name[10];	 // 문자배열로 된 이름
	int age; 		 // 나이를 나타내는 정수값
	double gpa;  	// 평균평점을 나타내는 실수값
} student;

int main(void)
{
	student* s;

	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}

	strcpy(s->name, "Park");
	s->age = 20;
	s->gpa = 4.2;

	printf("%s\t %d\t %f", s->name, s->age, s->gpa); // \t -> tab키 간격
	free(s);

	return 0;
}
