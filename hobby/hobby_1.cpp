#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

struct Planet {
    std::string name;
    double mu;       // �߷� ��� �� = G*M (m^3/s^2)
    double radius;   // �༺ ������ (m)
};

// ===== ���ӵ� ��� �Լ� (���� �˵� ������) =====
double acceleration(double r, double v, double m, double thrust, double mu) {
    double a_gravity = mu / (r * r);
    double v_circular = sqrt(mu / r);
    double a_thrust = thrust / m;
    return -a_gravity + (v < v_circular ? a_thrust : 0);
}

int main() {
    // ===== �༺ ���� =====
    std::string choice;
    Planet planet;

    std::cout << "�༺�� �����ϼ��� (earth/ksp): ";
    std::cin >> choice;

    if (choice == "earth") {
        planet.name = "Earth";
        planet.mu = 3.986e14;
        planet.radius = 6371000; // m
    }
    else if (choice == "ksp") {
        planet.name = "Kerbin";
        planet.mu = 3.5316e12;
        planet.radius = 600000; // m
    }
    else {
        std::cout << "�߸��� �����Դϴ�.\n";
        return 1;
    }

    // ===== ���� ���� =====
    std::string speedUnit, distUnit;
    std::cout << "�ӵ� ������ �����ϼ��� (m/s �Ǵ� km/s): ";
    std::cin >> speedUnit;
    std::cout << "�Ÿ�/�� ������ �����ϼ��� (m �Ǵ� km): ";
    std::cin >> distUnit;

    // ===== ����� �Է� =====
    double m, r, thrust;
    std::cout << "���ּ��� ���� (kg): ";
    std::cin >> m;

    std::cout << "���ּ��� " << planet.name << " �߽��� �ʱ� �Ÿ� (" << distUnit << "): ";
    std::cin >> r;
    if (distUnit == "km") r *= 1000; // m�� ��ȯ

    // ===== ���� �ӵ� ��� (�ʱ� �ӵ� �ڵ� ����) =====
    double v_curr = sqrt(planet.mu / r); // m/s
    std::cout << "���� �˵��� ���� �ӵ�: "
        << ((speedUnit == "km/s") ? v_curr / 1000 : v_curr)
        << " " << speedUnit << "\n";

    // ===== �ּ� �߷� =====
    double minThrust = 0.01; // N ����
    std::cout << "�˵� ������ �ּ� �߷�: " << minThrust << " N\n";

    std::cout << "����� ���� �߷� (N): ";
    std::cin >> thrust;

    // ===== CSV ���� �غ� =====
    std::ofstream file("simulation.csv");
    if (!file.is_open()) {
        std::cout << "CSV ������ �� �� �����ϴ�.\n";
        return 1;
    }
    file << "t(s),r(" << distUnit << "),v(" << speedUnit << ")\n";

    // ===== �ùķ��̼� ���� =====
    double dt = 1.0;
    double t = 0.0;
    double r_curr = r;

    std::cout << "\n=== RK4 �ùķ��̼� ���� (" << planet.name << ") ===\n";
    std::cout << "t(s)\tr(" << distUnit << ")\tv(" << speedUnit << ")\n";

    while (r_curr > planet.radius && t < 36000) {
        double k1_r = v_curr;
        double k1_v = acceleration(r_curr, v_curr, m, thrust, planet.mu);

        double k2_r = v_curr + 0.5 * dt * k1_v;
        double k2_v = acceleration(r_curr + 0.5 * dt * k1_r, v_curr + 0.5 * dt * k1_v, m, thrust, planet.mu);

        double k3_r = v_curr + 0.5 * dt * k2_v;
        double k3_v = acceleration(r_curr + 0.5 * dt * k2_r, v_curr + 0.5 * dt * k2_v, m, thrust, planet.mu);

        double k4_r = v_curr + dt * k3_v;
        double k4_v = acceleration(r_curr + dt * k3_r, v_curr + dt * k3_v, m, thrust, planet.mu);

        r_curr += (dt / 6.0) * (k1_r + 2 * k2_r + 2 * k3_r + k4_r);
        v_curr += (dt / 6.0) * (k1_v + 2 * k2_v + 2 * k3_v + k4_v);

        t += dt;

        if (fmod(t, 10) == 0)
            std::cout << t << "\t"
            << ((distUnit == "km") ? r_curr / 1000 : r_curr) << "\t"
            << ((speedUnit == "km/s") ? v_curr / 1000 : v_curr) << "\n";

        file << t << ","
            << ((distUnit == "km") ? r_curr / 1000 : r_curr) << ","
            << ((speedUnit == "km/s") ? v_curr / 1000 : v_curr) << "\n";

        if (r_curr <= planet.radius) {
            std::cout << "\n" << planet.name << " ǥ�鿡 �浹�߽��ϴ�. �� ���� �ð�: "
                << t / 60.0 << " ��\n";
            break;
        }
    }

    if (r_curr > planet.radius)
        std::cout << "\n10�ð� ������ " << planet.name << "�� �浹���� �ʾҽ��ϴ�.\n";

    std::cout << "�� �Է��� �߷����� �˵� ���� ���� Ȯ�� �����մϴ�.\n";
    file.close();
    std::cout << "�ùķ��̼� ����� simulation.csv ���Ͽ� ����Ǿ����ϴ�.\n";

    return 0;
}
