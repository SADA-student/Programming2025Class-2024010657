#include <stdio.h>

int main(void) {
    int a, b;

    printf("두 정수를 입력하세요: ");
    if (scanf("%d %d", &a, &b) != 2) {  // 입력이 2개가 아니면
        printf("잘못된 입력입니다.\n");
        return 1; // 프로그램 종료
    }

    printf("\n[사칙연산]\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);

    if (b != 0)
        printf("%d / %d = %.2f\n", a, b, (double)a / b);
    else
        printf("%d / %d = 나눌 수 없음\n", a, b);

    return 0;
}

