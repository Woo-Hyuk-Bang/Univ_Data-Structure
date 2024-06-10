/*
240318 순환
3번 - 하노이 탑
*/

#include <stdio.h>
#pragma warning(disable: 4996)
void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1) printf("원판 1을 %c 에서 %c으로 옮긴다.\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

int main(void)
{
    hanoi_tower(4, 'A', 'B', 'C');
        return 0;
}
