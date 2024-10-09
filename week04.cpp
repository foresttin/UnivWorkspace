// 예제 3-1 : Circle 클래스의 객체 생성 및 활용
#include <iostream>
using namespace std;

class Circle {  // 클래스 선언부
public:
    int radius;
    double getArea();
};

double Circle::getArea() {  // 클래스 구현부
    return 3.14*radius*radius;
}

int main() {
    Circle donut;   // Circle 타입의 donut 객체 생성
    donut.radius = 1;   // donut의 멤버 변수 접근
    double area = donut.getArea();  // donut의 멤버 함수 호출
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea(); // 변수 재사용
    cout << "pizza 면적은 " << area << endl;
}

// 실행 결과
donut 면적은 3.14
pizza 면적은 2826
 
// 예제 3-2 : Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle {
public:
    int width;
    int height;
    double getArea();
};

double Rectangle::getArea() {
    return width * height;
}

int main() {
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "사각형의 면적은 " << rect.getArea() << endl;
}

// 실행 결과
사각형의 면적은 15

// 예제 3-3 : 2개의 생성자를 가진 Circle 클래스
#include <iostream>
using namespace std;

class Circle {
public:
    int radius;
    Circle();   // 매개 변수 없는 생성자
    Circle(int r);  // 매개 변수 있는 생성자
    double getArea();
};

Circle::Circle() {
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "반지름 " << radius << " 원 생성 " << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;   // 매개 변수 없는 생성자 호출
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza(30);   // 매개 변수 있는 생성자 호출
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
}

// 실행 결과
반지름 1 원 생성
donut 면적은 3.14
반지름 30 원 생성 
pizza 면적은 2826

// 예제 3-4 : 생성자에서 다른 생성사 호출 연습 (위임 생성자 만들기)

#include <iostream>
using namespace std;

class Circle {
public:
    int radius;
    Circle();   // 위임 생성자
    Circle(int r);  // 타겟 생성자
    double getArea();
};

Circle::Circle() : Circle(1) {} // 위임 생성자

Circle::Circle(int r) {
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;   // 매개 변수 없는 생성자 호출
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza(30);   // 매개 변수 있는 생성자 호출
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
}

// 실행 결과
반지름 1 원 생성
donut 면적은 3.14
반지름 30 원 생성
pizza 면적은 2826
