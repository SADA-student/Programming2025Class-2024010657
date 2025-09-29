#include <stdio.h>

int main() {
    // 문자 변수
    char ch = 'A';

    // 문자열 변수 (const char*)
    const char* message = "First line\n\tIndented second line\nThird line";

    // 실수 변수
    float avg = 87.35;

    // 출력
    printf("=== Char/String & Escapes ===\n");
    printf("Char : %c, code: %d\n", ch, ch);
    printf("Message:\n%s\n", message);
    printf("Quotes: \"double quotes\" and 'single quotes'\n");
    printf("Backslash: \\\n");
    printf("Average: [%8.2f]\n", avg);

    return 0;
}
