#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

struct Planet {
    std::string name;
    double mu;       // 중력 상수 μ = G*M (m^3/s^2)
    double radius;   // 행성 반지름 (m)
};

// ===== 가속도 계산 함수 (원형 궤도 유지용) =====
double acceleration(double r, double v, double m, double thrust, double mu) {
    double a_gravity = mu / (r * r);
    double v_circular = sqrt(mu / r);
    double a_thrust = thrust / m;
    return -a_gravity + (v < v_circular ? a_thrust : 0);
}

int main() {
    // ===== 행성 선택 =====
    std::string choice;
    Planet planet;

    std::cout << "행성을 선택하세요 (earth/ksp): ";
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
        std::cout << "잘못된 선택입니다.\n";
        return 1;
    }

    // ===== 단위 선택 =====
    std::string speedUnit, distUnit;
    std::cout << "속도 단위를 선택하세요 (m/s 또는 km/s): ";
    std::cin >> speedUnit;
    std::cout << "거리/고도 단위를 선택하세요 (m 또는 km): ";
    std::cin >> distUnit;

    // ===== 사용자 입력 =====
    double m, r, thrust;
    std::cout << "우주선의 질량 (kg): ";
    std::cin >> m;

    std::cout << "우주선과 " << planet.name << " 중심의 초기 거리 (" << distUnit << "): ";
    std::cin >> r;
    if (distUnit == "km") r *= 1000; // m로 변환

    // ===== 공전 속도 계산 (초기 속도 자동 설정) =====
    double v_curr = sqrt(planet.mu / r); // m/s
    std::cout << "원형 궤도를 위한 속도: "
        << ((speedUnit == "km/s") ? v_curr / 1000 : v_curr)
        << " " << speedUnit << "\n";

    // ===== 최소 추력 =====
    double minThrust = 0.01; // N 단위
    std::cout << "궤도 유지용 최소 추력: " << minThrust << " N\n";

    std::cout << "사용할 엔진 추력 (N): ";
    std::cin >> thrust;

    // ===== CSV 파일 준비 =====
    std::ofstream file("simulation.csv");
    if (!file.is_open()) {
        std::cout << "CSV 파일을 열 수 없습니다.\n";
        return 1;
    }
    file << "t(s),r(" << distUnit << "),v(" << speedUnit << ")\n";

    // ===== 시뮬레이션 변수 =====
    double dt = 1.0;
    double t = 0.0;
    double r_curr = r;

    std::cout << "\n=== RK4 시뮬레이션 시작 (" << planet.name << ") ===\n";
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
            std::cout << "\n" << planet.name << " 표면에 충돌했습니다. 총 비행 시간: "
                << t / 60.0 << " 분\n";
            break;
        }
    }

    if (r_curr > planet.radius)
        std::cout << "\n10시간 내에는 " << planet.name << "에 충돌하지 않았습니다.\n";

    std::cout << "→ 입력한 추력으로 궤도 유지 여부 확인 가능합니다.\n";
    file.close();
    std::cout << "시뮬레이션 결과가 simulation.csv 파일에 저장되었습니다.\n";

    return 0;
}
