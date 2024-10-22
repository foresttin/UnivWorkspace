// 예제 5-2 : 객체 리턴
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
};

Circle getCircle() {
    Circle tmp(30);
    return tmp;
}

int main() {
    Circle c;
    cout << c.getArea() << endl;

    c = getCircle();
    cout << c.getArea() << endl;
}

// 실행 결과
3.14
2826

// 예제 5-3 : 기본 타입 변수에 대한 참조
#include <iostream>
using namespace std;

int main() {
    cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
    int i = 1;
    int n = 2;
    int &refn = n;
    n = 4;
    refn++;
    cout << i << '\t' << n << '\t' << refn << endl;

    refn = i;
    refn++;
    cout << i << '\t' << n << '\t' << refn << endl;

    int *p = &refn;
    *p = 20;
    cout << i << '\t' << n << '\t' << refn << endl;
}

// 실행 결과
i       n       refn
1       5       5
1       2       2
1       20      20

// 예제 5-4 : 객체에 대한 참조
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
};

int main() {
    Circle circle;
    Circle &refc = circle;
    refc.setRadius(10);
    cout << refc.getArea() << " " << circle.getArea();
}

// 실행 결과
314 314
