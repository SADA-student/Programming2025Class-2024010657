#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "�� ������ �Է��ϼ���: ";         //cout : ����� ȭ�鿡 ����ϴ� ��ü
    cin >> a >> b;                            //cin : ����� �Է��� �޴� ��ü

    cout << "��: " << a + b << "\n";
    cout << "��: " << a * b << "\n";
    cout << "���� ���� ����: " << a << " > " << b << " = " << (a > b) << "\n";
    cout << "�� ���� ����: (a>0)&&(b>0) = " << ((a > 0) && (b > 0)) << "\n";

    return 0;
}