#include <iostream>
#include <cmath>
#include <map>
#include <string>
using namespace std;

// 표준 중력 가속도 (m/s²)
const double g0 = 9.80665;

// KSP 주요 천체의 저궤도 진입 Δv (m/s)
const map<string, double> orbitDv = {
    {"Kerbin", 3400},
    {"Mun", 580},
    {"Minmus", 180},
    {"Duna", 1450},
    {"Eve", 5400},
    {"Laythe", 2900},
    {"Tylo", 2270}
};

// Δv 계산 (Tsiolkovsky 로켓 방정식)
double calcDeltaV(double m0, double mf, double Isp) {
    return Isp * g0 * log(m0 / mf);
}

int main() {
    cout << "=== Δv 계산기 (KSP용) ===\n";

    // 사용자 입력
    double dryMass, fuelMass, Isp;
    string body;

    cout << "행성 이름 (Kerbin, Duna, Eve 등): ";
    cin >> body;
    cout << "로켓의 건조 질량 (t): ";
    cin >> dryMass;
    cout << "연료 질량 (t): ";
    cin >> fuelMass;
    cout << "엔진 Isp (초): ";
    cin >> Isp;

    // 단위 변환
    dryMass *= 1000;   // ton → kg
    fuelMass *= 1000;  // ton → kg

    // 질량 계산
    double m0 = dryMass + fuelMass;  // 초기 질량
    double mf = dryMass;             // 연료 소모 후 질량

    // Δv 계산
    double deltaV = calcDeltaV(m0, mf, Isp);

    // 행성 존재 확인
    if (orbitDv.find(body) == orbitDv.end()) {
        cout << "⚠️  알 수 없는 천체 이름입니다.\n";
        return 1;
    }

    double requiredDv = orbitDv.at(body);

    cout << "\n=== 결과 ===\n";
    cout << "총 Δv: " << deltaV << " m/s\n";
    cout << body << " 저궤도 진입 필요 Δv: " << requiredDv << " m/s\n";

    if (deltaV >= requiredDv)
        cout << "✅ 이론상 " << body << " 궤도 진입 가능!\n";
    else
        cout << "❌ 궤도 진입 불가능 — Δv가 부족합니다.\n";

    return 0;
}
