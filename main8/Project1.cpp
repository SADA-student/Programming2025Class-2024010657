#include <stdio.h>

int main(void) {
    
    char char_val = 'A';
    int ascii_code = (int)char_val;

    const char* header = "=== Char/String & Escapes ===";
    const char* message = "Message:";
    const char* quotes_text = "Quotes: \"double quotes\" and 'single quotes'";

    
    double average_val = 87.35;
    printf("%s\n", header); 

    printf("Char : %c, code: %d\n", char_val, ascii_code);

    printf("%s\n", message); 

    printf("First line\n"); 

   
    printf("    Indented second line\n"); 

    printf("Third line\n"); 

   
    printf("%s\n", quotes_text); 

    printf("Backslash: \\\n"); 

    printf("Average: [ %.2f]\n", average_val); 

    return 0;
}