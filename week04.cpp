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

// 예제 3-5 : 멤버변수의 초기화와 위임 생성자 활용
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point();
    Point(int a, int b);
    void show() { cout << "(" << x << "," << y << ")" << endl; }
};

Point::Point() : Point(0,0) {} // 위임 생성자
Point::Point(int a, int b) // 타겟 생성자
    : x(a), y(b) {}

int main() {
    Point origin;
    Point target(10, 20);
    origin.show();
    target.show();
}

// 실행 결과
(0,0)
(10,20)

// 예제 3-6 : Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle {
public:
    int width=1 , height=1;
    int a, b, c;
    Rectangle();
    Rectangle(int a, int b);
    Rectangle(int c);
    bool isSquare();
};

Rectangle::Rectangle() : Rectangle(1) {}    // 위임 생성자

Rectangle::Rectangle(int a, int b) {
    width = a;
    height = b;
}
Rectangle::Rectangle(int c) {   // 타겟 생성자
    width = height = c;
}

bool Rectangle::isSquare() {    // 정사각형이면 true를 리턴하는 멤버 함수
    if(width == height) return true;
    else return false;
}

int main() {
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);
    
    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}

// 실행 결과
rect1은 정사각형이다.
rect3는 정사각형이다.
// 예제 3-7 : Circle 클래스에 소멸자 작성 및 실행
#include <iostream>
using namespace std;

class Circle {
public:
    int radius;

    Circle();
    Circle(int r);
    ~Circle();  // 소멸자
    double getArea();
};

Circle::Circle(){
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
    cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;
    Circle pizza(30);

    return 0;   // main() 함수가 종료되면 main() 함수의 스택에 생성된 객체가 소멸된다.
}

// 실행 결과
반지름 1 원 생성
반지름 30 원 생성
반지름 30 원 소멸
반지름 1 원 소멸
