#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { return (float)a / b; }
int mod(int a, int b) { return a % b; }

int main(void) 
{
    int x, y;
    int ret; // scanf 반환값 저장용 변수

    printf("두 정수를 입력하세요: ");
    ret = scanf("%d %d", &x, &y);

    if (ret != 2) 
    {
        printf("입력 오류가 발생했습니다.\n");
        return 1; // 비정상 종료
    }

    printf("덧셈 결과: %d\n", add(x, y));
    printf("뺄셈 결과: %d\n", sub(x, y));
    printf("곱셈 결과: %d\n", mul(x, y));
    printf("나눗셈 결과: %.2f\n", divi(x, y));
    printf("나머지 결과: %d\n", mod(x, y));

    return 0;
}