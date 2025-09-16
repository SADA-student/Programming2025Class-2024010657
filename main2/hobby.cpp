#include <iostream> 
/*gpt를 이용해 만듦(우주선의 질량, 속도, 지구와의 거리를 입력받아 
  운동 에너지, 중력 퍼텐셜 에너지, 전체 역학적 에너지, 탈출 속도를 
  계산하고 우주선이 지구 궤도를 유지할 수 있는지 판단하는 프로그램)*/
#include <cmath>  // pow() 함수 사용을 위해 필요

// 상수 정의
const double G = 6.67430e-11;  // 만유인력 상수 (단위: m^3 kg^-1 s^-2)
const double M = 5.972e24;     // 지구의 질량 (단위: kg)
const double R_EARTH = 6371000; // 지구 반지름 (단위: m)

int main() {
    // 변수 선언
    double m, v, r;

    // 사용자로부터 값 입력받기
    std::cout << "우주선의 질량 (kg): ";
    std::cin >> m;

    std::cout << "우주선의 속도 (m/s): ";
    std::cin >> v;

    std::cout << "우주선과 지구 중심의 거리 (m): ";
    std::cin >> r;

    // 운동 에너지 계산
    double K = 0.5 * m * pow(v, 2);

    // 중력 퍼텐셜 에너지 계산
    double U = -(G * M * m) / r;

    // 전체 역학적 에너지 (E = K + U)
    double E = K + U;

    // 탈출 속도 계산 (v_esc = sqrt(2GM / r))
    double v_esc = sqrt((2 * G * M) / r);

    // 결과 출력
    std::cout << "\n운동 에너지 (K): " << K << " Joules" << std::endl;
    std::cout << "중력 퍼텐셜 에너지 (U): " << U << " Joules" << std::endl;
    std::cout << "전체 역학적 에너지 (E = K + U): " << E << " Joules" << std::endl;
    std::cout << "탈출 속도 (v_esc): " << v_esc << " m/s" << std::endl;

    // 우주선이 지구 궤도에 안정적으로 있을 수 있는지 판단
    if (v >= v_esc) {
        std::cout << "우주선은 지구의 중력을 벗어날 수 있습니다." << std::endl;
    }
    else {
        std::cout << "우주선은 지구의 궤도를 유지할 수 있습니다." << std::endl;
    }

    return 0;
}
