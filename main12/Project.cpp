#include <stdio.h>

int main() 
{
    int choice;
    int a;

    // ��� ��� ����
    printf("��� ����� �����ϼ���:\n");
    printf("1. 2�ܺ��� a�ܱ��� ���\n");
    printf("2. Ư�� �� a�� ���\n");
    printf("���� (1 �Ǵ� 2): ");
    scanf("%d", &choice);

    // �� �� �Է�
    printf("���� ���� a�� �Է��ϼ��� (���): ");
    scanf("%d", &a);

    if (a < 1) 
    {
        printf("����: a�� 1 �̻��� ������� �մϴ�.\n");
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
        printf("�߸��� �����Դϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    return 0;
}
