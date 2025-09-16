#include <iostream> 
/*gpt�� �̿��� ����(���ּ��� ����, �ӵ�, �������� �Ÿ��� �Է¹޾� 
  � ������, �߷� ���ټ� ������, ��ü ������ ������, Ż�� �ӵ��� 
  ����ϰ� ���ּ��� ���� �˵��� ������ �� �ִ��� �Ǵ��ϴ� ���α׷�)*/
#include <cmath>  // pow() �Լ� ����� ���� �ʿ�

// ��� ����
const double G = 6.67430e-11;  // �����η� ��� (����: m^3 kg^-1 s^-2)
const double M = 5.972e24;     // ������ ���� (����: kg)
const double R_EARTH = 6371000; // ���� ������ (����: m)

int main() {
    // ���� ����
    double m, v, r;

    // ����ڷκ��� �� �Է¹ޱ�
    std::cout << "���ּ��� ���� (kg): ";
    std::cin >> m;

    std::cout << "���ּ��� �ӵ� (m/s): ";
    std::cin >> v;

    std::cout << "���ּ��� ���� �߽��� �Ÿ� (m): ";
    std::cin >> r;

    // � ������ ���
    double K = 0.5 * m * pow(v, 2);

    // �߷� ���ټ� ������ ���
    double U = -(G * M * m) / r;

    // ��ü ������ ������ (E = K + U)
    double E = K + U;

    // Ż�� �ӵ� ��� (v_esc = sqrt(2GM / r))
    double v_esc = sqrt((2 * G * M) / r);

    // ��� ���
    std::cout << "\n� ������ (K): " << K << " Joules" << std::endl;
    std::cout << "�߷� ���ټ� ������ (U): " << U << " Joules" << std::endl;
    std::cout << "��ü ������ ������ (E = K + U): " << E << " Joules" << std::endl;
    std::cout << "Ż�� �ӵ� (v_esc): " << v_esc << " m/s" << std::endl;

    // ���ּ��� ���� �˵��� ���������� ���� �� �ִ��� �Ǵ�
    if (v >= v_esc) {
        std::cout << "���ּ��� ������ �߷��� ��� �� �ֽ��ϴ�." << std::endl;
    }
    else {
        std::cout << "���ּ��� ������ �˵��� ������ �� �ֽ��ϴ�." << std::endl;
    }

    return 0;
}
