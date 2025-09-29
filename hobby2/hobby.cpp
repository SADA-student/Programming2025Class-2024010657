#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

// ===== 행성 상수 구조체 =====
struct Planet {
    std::string name;
    double mu;     // 중력 상수 (m^3/s^2)
    double radius; // 행성 반지름 (m)
};

// ===== 가속도 계산 함수 (벡터) =====
void acceleration(double x, double y, double m, double thrust, double& ax, double& ay, double mu) {
    double r = std::sqrt(x * x + y * y);
    // 중력 가속도 (행성 중심 방향)
    double a_grav = -mu / (r * r);

    ax = a_grav * (x / r);
    ay = a_grav * (y / r);

    // 추력: 단순화 (반지름 방향 위쪽)
    if (thrust > 0) {
        ax += (thrust / m) * (x / r);
        ay += (thrust / m) * (y / r);
    }
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
        planet.radius = 6371000;
    }
    else if (choice == "ksp") {
        planet.name = "Kerbin";
        planet.mu = 3.5316e12;
        planet.radius = 600000;
    }
    else {
        std::cout << "잘못된 선택입니다.\n";
        return 1;
    }

    // ===== 사용자 입력 =====
    double m, vx, vy, h, thrust;
    std::cout << "우주선의 질량 (kg): ";
    std::cin >> m;
    std::cout << "초기 고도 (m): ";
    std::cin >> h;
    std::cout << "초기 속도 (vx vy, m/s): ";
    std::cin >> vx >> vy;
    std::cout << "사용할 엔진 추력 (N): ";
    std::cin >> thrust;

    // ===== 초기 위치 (해수면 기준) =====
    double r0 = planet.radius + h;
    double x = r0;
    double y = 0.0;

    // ===== CSV 파일 준비 =====
    std::ofstream file("orbit_simulation.csv");
    if (!file.is_open()) {
        std::cout << "CSV 파일을 열 수 없습니다.\n";
        return 1;
    }
    file << "t,x,y,vx,vy\n";

    // ===== 시뮬레이션 변수 =====
    double dt = 1.0;
    double t = 0.0;

    std::cout << "\n=== 2D 궤도 시뮬레이션 시작 (" << planet.name << ") ===\n";
    std::cout << "t(s)\tx(m)\ty(m)\tvx(m/s)\tvy(m/s)\n";

    // ===== 시뮬레이션 루프 =====
    while (t < 20000) {
        double r = std::sqrt(x * x + y * y);

        // --- 지표면 충돌 체크 ---
        if (r <= planet.radius) {
            std::cout << "\n" << planet.name << " 표면에 충돌했습니다. 총 비행 시간: "
                << t / 60.0 << " 분\n";
            break;
        }

        // --- 현재 속도 계산 ---
        double v = std::sqrt(vx * vx + vy * vy);
        double v_orbit = std::sqrt(planet.mu / r);

        // --- 궤도 상실 시 종료 ---
        if (v < v_orbit) {
            std::cout << "\n속도가 원궤도 속도보다 낮아 궤도를 유지할 수 없습니다. 총 비행 시간: "
                << t / 60.0 << " 분\n";
            break;
        }

        // --- 가속도 계산 ---
        double ax, ay;
        acceleration(x, y, m, thrust, ax, ay, planet.mu);

        // --- 위치/속도 업데이트 (오일러 방식) ---
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;

        t += dt;

        // 10초마다 출력
        if (fmod(t, 10) == 0)
            std::cout << t << "\t" << x << "\t" << y << "\t" << vx << "\t" << vy << "\n";

        // CSV에 저장
        file << t << "," << x << "," << y << "," << vx << "," << vy << "\n";
    }

    if (t >= 20000)
        std::cout << "\n시뮬레이션 시간 내에 충돌하지 않았습니다.\n";

    file.close();
    std::cout << "결과가 orbit_simulation.csv 파일에 저장되었습니다.\n";

    return 0;
}
