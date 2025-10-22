#include <stdio.h>

int main() 
{
    int choice;
    int a;

    // 출력 방식 선택
    printf("출력 방식을 선택하세요:\n");
    printf("1. 2단부터 a단까지 출력\n");
    printf("2. 특정 단 a만 출력\n");
    printf("선택 (1 또는 2): ");
    scanf("%d", &choice);

    // 단 수 입력
    printf("단의 숫자 a를 입력하세요 (양수): ");
    scanf("%d", &a);

    if (a < 1) 
    {
        printf("오류: a는 1 이상의 양수여야 합니다.\n");
        return 1;
    }

    if (choice == 1) 
    {
        for (int i = 2; i <= a; ++i) 
        {
            for (int j = 1; j <= 9; ++j) 
            {
                printf("%d * %d = %d\n", i, j, i * j);
            }
            printf("\n");
        }
    }
    else if (choice == 2) 
    {
        for (int j = 1; j <= 9; ++j) 
        {
            printf("%d * %d = %d\n", a, j, a * j);
        }
    }
    else 
    {
        printf("잘못된 선택입니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    return 0;
}
