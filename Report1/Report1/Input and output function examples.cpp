#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "두 정수를 입력하세요: ";         //cout : 결과를 화면에 출력하는 객체
    cin >> a >> b;                            //cin : 사용자 입력을 받는 객체

    cout << "합: " << a + b << "\n";
    cout << "곱: " << a * b << "\n";
    cout << "관계 연산 예시: " << a << " > " << b << " = " << (a > b) << "\n";
    cout << "논리 연산 예시: (a>0)&&(b>0) = " << ((a > 0) && (b > 0)) << "\n";

    return 0;
}