// 선택정렬 프로그램 특징을 기억해놓도록 하자.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
   int i, j, least, temp;
   for (i = 0; i < n - 1; i++) {
      least = i;
      for (j = i + 1; j < n; j++) // 최소값 탐색
         if (list[j] < list[least]) least = j;
         SWAP(list[i], list[least], temp);
      }
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력 
      list[i] = rand() % 100; // 난수 발생 범위 0~99

   selection_sort(list, n); // 선택정렬 호출(void selection_sort)
   for (i = 0; i < n; i++) printf("%d ", list[i]);
   printf("\n");
   return 0;
}

// 삽입정렬 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

// 삽입정렬 프로그램

void insertion_sort(int list[], int n)
{
   int i, j, key;
   for (i = 1; i < n; i++) {
      key = list[i];
      for (j = i - 1; j >= 0 && list[j] > key; j--)
         list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
      list[j + 1] = key;
   }
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력 
      list[i] = rand() % 100; // 난수 발생 범위 0~99

   insertion_sort(list, n); // 삽입정렬 호출 
   for (i = 0; i < n; i++)
      printf("%d ", list[i]);
   printf("\n");
   return 0;
}

// 버블정렬 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void bubble_sort(int list[], int n)
{
   int i, j, temp;
   for (i = n - 1; i > 0; i--) {
      for (j = 0; j < i; j++)
         /* 앞뒤의 레코드를 비교한 후 교체 */
         if (list[j] > list[j + 1]) SWAP(list[j], list[j + 1], temp);
   }
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력 
      list[i] = rand() % 100; // 난수 발생 범위 0~99

   bubble_sort(list, n); // 삽입정렬 호출 
   for (i = 0; i < n; i++) printf("%d ", list[i]);
   printf("\n");
   return 0;
}

// 퀵 정렬 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void quick_sort(int list[], int left, int right)
{
   if (left < right) {
      int q = partition(list, left, right);
      quick_sort(list, left, q - 1);
      quick_sort(list, q + 1, right);
   }
}

int partition(int list[], int left, int right)
{
   int pivot, temp;
   int low, high;

   low = left;
   high = right + 1;
   pivot = list[left];
   do {
         do
            low++;
         while (list[low] < pivot);
         do
            high--;
         while (list[high] > pivot);
         if (low < high) SWAP(list[low], list[high], temp);
   } while (low < high);

   SWAP(list[left], list[high], temp);
   return high;
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력 
      list[i] = rand() % 100;

   quick_sort(list, 0, n - 1); // 퀵정렬 호출 
   for (i = 0; i < n; i++) printf("%d ", list[i]);
   printf("\n");
   return 0;
}


// 퀵 정렬 프로그램 (라이브러리 함수) qsort 함수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int compare(const void* arg1, const void* arg2)
{
   if (*(double*)arg1 > *(double*)arg2) return 1;
   else if (*(double*)arg1 == *(double*)arg2) return 0;
   else return -1;
}

int main(void)
{
   int i;
   double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };
   qsort((void*)list, (size_t)5, sizeof(double), compare);
   for (i = 0; i < 5; i++) printf("%f", list[i]);
   printf("\n");
   return 0;
}


// 기수 정렬 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct { // 큐 타입
element  data[MAX_QUEUE_SIZE];
int  front, rear;
} QueueType;

// 오류 함수
void error(const char* message)
{   fprintf(stderr, "%s\n", message);
    exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{   q->front = q->rear = 0;	}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{   return (q->front == q->rear);     }

// 포화 상태 검출 함수
int is_full(QueueType* q)
{   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);   }

// 삽입 함수
void enqueue(QueueType* q, element item)
{   if (is_full(q)) error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;		}

// 삭제 함수
element dequeue(QueueType* q)
{   if (is_empty(q)) error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];		}

#define BUCKETS 10
#define DIGITS  4
void radix_sort(int list[], int n)
{   int i, b, d, factor = 1;
   QueueType queues[BUCKETS];

   for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);  // 큐들의 초기화
   for (d = 0; d < DIGITS; d++) {
      for (i = 0; i < n; i++)// 데이터들을 자리수에 따라 큐에 삽입
         enqueue(&queues[(list[i] / factor) % 10], list[i]);

    for (b = i = 0; b < BUCKETS; b++)  // 버킷에서 꺼내어 list로 합친다.
       while (!is_empty(&queues[b]))
          list[i++] = dequeue(&queues[b]);
    factor *= 10;// 그 다음 자리수로 간다.
    }
}

#define  SIZE 10

int main(void)
{
   int list[SIZE];
   srand(time(NULL));
   // 난수 생성 및 출력
   for (int i = 0; i < SIZE; i++)
      list[i] = rand() % 100;

   radix_sort(list, SIZE); // 기수정렬 호출 
   for (int i = 0; i < SIZE; i++)
      printf("%d ", list[i]);
   printf("\n");
   return 0;
}

// 영어사전 정렬(버블 정렬)

#define  SIZE 10

int main(void)
{
   int list[SIZE];
   srand(time(NULL));
   // 난수 생성 및 출력
   for (int i = 0; i < SIZE; i++)
      list[i] = rand() % 100;

   radix_sort(list, SIZE); // 기수정렬 호출 
   for (int i = 0; i < SIZE; i++)
      printf("%d ", list[i]);
   printf("\n");
   return 0;
}

int main(void)
{
   int i, j;
   element temp;

   printf("5개의 단어와 의미를 입력하시오\n");

   for (i = 0; i < SIZE; i++) {
      scanf("%s[^\n]", list[i].word);// 엔터키만을 제외하고 받는다.
      scanf("%s[^\n]", list[i].meaning);// 엔터키만을 제외하고 받는다.
   }

   // 버블 정렬
   for (i = 0; i < SIZE - 1; ++i) {
      for (j = i + 1; j < SIZE; ++j) {
         if (strcmp(list[i].word, list[j].word) > 0) {
            SWAP(list[i], list[j], temp);
         }
      }
   }

   printf("\n정렬 후 사전의 내용: \n");
   for (i = 0; i < SIZE; i++) {
      printf("%s: %s \n", list[i].word, list[i].meaning);
   }

   return 0;
}
