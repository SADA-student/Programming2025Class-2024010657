#include <stdio.h>

int main() {
    // ���� ����
    char ch = 'A';

    // ���ڿ� ���� (const char*)
    const char* message = "First line\n\tIndented second line\nThird line";

    // �Ǽ� ����
    float avg = 87.35;

    // ���
    printf("=== Char/String & Escapes ===\n");
    printf("Char : %c, code: %d\n", ch, ch);
    printf("Message:\n%s\n", message);
    printf("Quotes: \"double quotes\" and 'single quotes'\n");
    printf("Backslash: \\\n");
    printf("Average: [%8.2f]\n", avg);

    return 0;
}
