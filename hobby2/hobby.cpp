#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

// ===== �༺ ��� ����ü =====
struct Planet {
    std::string name;
    double mu;     // �߷� ��� (m^3/s^2)
    double radius; // �༺ ������ (m)
};

// ===== ���ӵ� ��� �Լ� (����) =====
void acceleration(double x, double y, double m, double thrust, double& ax, double& ay, double mu) {
    double r = std::sqrt(x * x + y * y);
    // �߷� ���ӵ� (�༺ �߽� ����)
    double a_grav = -mu / (r * r);

    ax = a_grav * (x / r);
    ay = a_grav * (y / r);

    // �߷�: �ܼ�ȭ (������ ���� ����)
    if (thrust > 0) {
        ax += (thrust / m) * (x / r);
        ay += (thrust / m) * (y / r);
    }
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
        planet.radius = 6371000;
    }
    else if (choice == "ksp") {
        planet.name = "Kerbin";
        planet.mu = 3.5316e12;
        planet.radius = 600000;
    }
    else {
        std::cout << "�߸��� �����Դϴ�.\n";
        return 1;
    }

    // ===== ����� �Է� =====
    double m, vx, vy, h, thrust;
    std::cout << "���ּ��� ���� (kg): ";
    std::cin >> m;
    std::cout << "�ʱ� �� (m): ";
    std::cin >> h;
    std::cout << "�ʱ� �ӵ� (vx vy, m/s): ";
    std::cin >> vx >> vy;
    std::cout << "����� ���� �߷� (N): ";
    std::cin >> thrust;

    // ===== �ʱ� ��ġ (�ؼ��� ����) =====
    double r0 = planet.radius + h;
    double x = r0;
    double y = 0.0;

    // ===== CSV ���� �غ� =====
    std::ofstream file("orbit_simulation.csv");
    if (!file.is_open()) {
        std::cout << "CSV ������ �� �� �����ϴ�.\n";
        return 1;
    }
    file << "t,x,y,vx,vy\n";

    // ===== �ùķ��̼� ���� =====
    double dt = 1.0;
    double t = 0.0;

    std::cout << "\n=== 2D �˵� �ùķ��̼� ���� (" << planet.name << ") ===\n";
    std::cout << "t(s)\tx(m)\ty(m)\tvx(m/s)\tvy(m/s)\n";

    // ===== �ùķ��̼� ���� =====
    while (t < 20000) {
        double r = std::sqrt(x * x + y * y);

        // --- ��ǥ�� �浹 üũ ---
        if (r <= planet.radius) {
            std::cout << "\n" << planet.name << " ǥ�鿡 �浹�߽��ϴ�. �� ���� �ð�: "
                << t / 60.0 << " ��\n";
            break;
        }

        // --- ���� �ӵ� ��� ---
        double v = std::sqrt(vx * vx + vy * vy);
        double v_orbit = std::sqrt(planet.mu / r);

        // --- �˵� ��� �� ���� ---
        if (v < v_orbit) {
            std::cout << "\n�ӵ��� ���˵� �ӵ����� ���� �˵��� ������ �� �����ϴ�. �� ���� �ð�: "
                << t / 60.0 << " ��\n";
            break;
        }

        // --- ���ӵ� ��� ---
        double ax, ay;
        acceleration(x, y, m, thrust, ax, ay, planet.mu);

        // --- ��ġ/�ӵ� ������Ʈ (���Ϸ� ���) ---
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;

        t += dt;

        // 10�ʸ��� ���
        if (fmod(t, 10) == 0)
            std::cout << t << "\t" << x << "\t" << y << "\t" << vx << "\t" << vy << "\n";

        // CSV�� ����
        file << t << "," << x << "," << y << "," << vx << "," << vy << "\n";
    }

    if (t >= 20000)
        std::cout << "\n�ùķ��̼� �ð� ���� �浹���� �ʾҽ��ϴ�.\n";

    file.close();
    std::cout << "����� orbit_simulation.csv ���Ͽ� ����Ǿ����ϴ�.\n";

    return 0;
}
