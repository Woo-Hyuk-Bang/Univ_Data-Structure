#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_ELEMENTS 1000//10000000L
int list[MAX_ELEMENTS];
int count;// 수행횟수

// 이진 탐색
int binsearch(int list[], int n, int searchnum)
{
   int left = 0;
   int right = n - 1;
   int middle;
   count = 0;
   while (left <= right) {// 아직 숫자들이 남아 있으면
      count++;
      middle = (left + right) / 2;
      if (searchnum == list[middle]) return middle;
      else if (searchnum < list[middle]) right = middle - 1;
         else left = middle + 1;
   }
   return -1;// 발견되지 않음 
}

// 순차 탐색
int seqsearch(int list[], int n, int searchnum)
{
   int i;

   count = 0;
   for (i = 0; i < n; i++) {
      count++;
      if (searchnum == list[i]) return i;
   }
   return -1;// 발견되지 않음 
}

int main()
{  
    int i, value = 1;
    int search_number;
    int return_value;
    clock_t start, finish;
    clock_t  duration;
    list[0] = 0;
    for (i = 1; i < MAX_ELEMENTS; i++)
    {   list[i] = value;
         value = value + 2;
    }
    printf("숫자를 입력하시요:");
    scanf("%d", &search_number);

    start = clock();
    return_value = seqsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d milliseconds\n", duration);
    printf("순차탐색의 수행횟수=%d\n\n ", count);

    start = clock();
    return_value = binsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d milliseconds\n", duration);
    printf("이진탐색의 수행횟수=%d\n ", count);
    if (return_value == -1) printf("숫자가 발견되지 않았습니다.\n");
    else printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);  
}

// 색인 순차탐색 프로그램

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 1000
#define INDEX_SIZE 10

int list[MAX_SIZE] = { 3, 9,15, 22, 31, 55, 67, 88, 91 };
int n = 9;
typedef struct {
   int key;
   int index;
} itable;
itable index_list[INDEX_SIZE] = { {3,0}, {15,3}, {67,6} };

int seq_search(int key, int low, int high)
{
   int i;
   for (i = low; i <= high; i++)
   if (list[i] == key) return i;  /* 탐색에 성공하면 키 값의 인덱스 반환 */
   return -1;    /* 탐색에 실패하면 -1 반환 */
}

/* INDEX_SIZE는 인덱스 테이블의 크기,n은 전체 데이터의 수 */
int index_search(int key)
{
   int i, low, high;
   /* 키 값이 리스트 범위 내의 값이 아니면 탐색 종료 */
   if (key<list[0] || key>list[n - 1]) return -1;
   
   /* 인덱스 테이블을 조사하여 해당키의 구간 결정 */
   for (i = 0; i < INDEX_SIZE; i++)
      if (index_list[i].key <= key && index_list[i + 1].key > key) break;
   if (i == INDEX_SIZE) {  /* 인덱스테이블의 끝이면 */
      low = index_list[i - 1].index;
      high = n;
      }
   else {
      low = index_list[i].index;
      high = index_list[i + 1].index;
   }
   /* 예상되는 범위만 순차 탐색 */
   return seq_search(key, low, high);
}

void main()
{
   int i;
   i = index_search(67);
   if (i >= 0) printf("탐색 성공 i=%d\n", i);
   else printf("탐색 실패\n");
}

// 보간탐색 프로그램

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#define MAX_SIZE 1000
int list[MAX_SIZE];

int init_list()
{
   int i;
   for (i = 0; i < 1000; i++)
   list[i] = 7 * i;
   return 0;
}

int search_binary(int key, int low, int high)
{
   int middle;
   if (low <= high) {
      middle = (low + high) / 2;
      if (key == list[middle]) return middle;  // 탐색 성공
      else if (key < list[middle]) // 왼쪽 부분리스트 탐색 
         return search_binary(key, low, middle - 1);
      else                   // 오른쪽 부분리스트 탐색 
         return search_binary(key, middle + 1, high);
   }
   return -1;        // 탐색 실패
}

int search_binary2(int key, int low, int high)
{
    int middle;
   while (low <= high) {       // 아직 숫자들이 남아 있으면
      middle = (low + high) / 2;
      if (key == list[middle]) return middle;
      else if (key > list[middle]) low = middle + 1;
      else high = middle - 1;
   }
   return -1;   // 발견되지 않음 
}

int search_interpolation(int key, int n)
{
   int low, high, j;
   low = 0;
   high = n - 1;
   while ((list[high] >= key) && (key > list[low])) {
      j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
      if (key > list[j]) low = j + 1;
      else if (key < list[j]) high = j - 1;
      else low = j;
   }
   if (list[low] == key) return(low);  //found(r[low])
   else return -1;  // notfound(key)
}

int main()
{
   int i = 0;
   init_list();
   i = search_binary2(49, 0, 999);
   if (i >= 0) printf("탐색 성공 i=%d\n", i);
   else printf("탐색 실패\n");
}
