#include <stdio.h>

// 1. 구조체(struct) 정의: 모든 멤버가 독립적인 공간을 가짐
// 예상 크기: int(4) + char(1) + double(8) = 13 (패딩으로 인해 더 커질 수 있음)
struct DataStruct {
    int num;
    char ch;
    double dval;
};

// 2. 공용체(union) 정의: 모든 멤버가 메모리 공간을 공유
// 크기: 가장 큰 멤버인 double(8)의 크기로 결정됨
union DataUnion {
    int num;
    char ch;
    double dval;
};

int main(void) {
    // 구조체 및 공용체 변수 선언
    struct DataStruct s;
    union DataUnion u;

    // --- 1. 메모리 크기 비교 ---
    printf("## 1. 메모리 크기 비교\n");
    printf("구조체 크기 (sizeof(DataStruct)): %zu 바이트\n", sizeof(struct DataStruct));
    printf("공용체 크기 (sizeof(DataUnion)): %zu 바이트\n", sizeof(union DataUnion));
    printf("-------------------------------------------\n");

    // --- 2. 공용체의 메모리 공유 확인 ---
    printf("## 2. 공용체 메모리 공유 확인\n");

    // 공용체에 int 값 대입
    u.num = 12345;
    printf("1) u.num = 12345 대입 후:\n");
    printf("  u.num: %d\n", u.num);
    // 이 시점에서 u.dval과 u.ch의 값은 의미 없는 값이 됩니다 (훼손).
    printf("  u.dval: %.2lf (값이 훼손될 수 있음)\n", u.dval);

    // 공용체에 double 값 대입
    u.dval = 3.14159;
    printf("\n2) u.dval = 3.14159 대입 후:\n");
    printf("  u.dval: %.5lf\n", u.dval);

    // 가장 큰 멤버인 double에 새 값이 저장되면서,
    // 이전에 저장했던 u.num과 u.ch의 값은 훼손됩니다 (Overwrite). 
    printf("  u.num: %d (값이 훼손됨)\n", u.num);

    printf("-------------------------------------------\n");

    return 0;
}