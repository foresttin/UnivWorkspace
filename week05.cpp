// 예제 4-1 : 객체 포인터 선언 및 활용
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    double getArea();
};

double Circle::getArea() {
    return  3.14*radius*radius;
}

int main() {
    Circle donut;
    Circle pizza(30);

    cout << donut.getArea() << endl;

    Circle *p;
    p = &donut;
    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;

    p = &pizza;
    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;
}

// 실행 결과
3.14
3.14
3.14
2826
2826

// 예제 4-2 : Circle 클래스의 배열 선언 및 활용
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle circleArray[3];

    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for(int i=0; i<3; i++)
        cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;

    Circle *p;
    p = circleArray;
    for(int i=0; i<3; i++) {
        cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
        p++;
    }
}

// 실행 결과
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 2826
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 2826

// 예제 4-3 : 객체 배열 초기화
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

    for(int i=0; i<3; i++)
        cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
}

// 실행 결과
Circle 0의 면적은 314
Circle 1의 면적은 1256
Circle 2의 면적은 3.14

// 예제 4-4 : Circle 클래스의 2차원 배열 선언 및 활용

#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea() {
    return 3.14*radius*radius;
}
 
int main() {
    Circle circles[2][3];

    circles[0][0].setRadius(1);
    circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++) {
            cout << "Circle [" << i << "," << j << "]의 면적은 ";
            cout << circles[i][j].getArea() << endl;        
        }
}

// 실행 결과
Circle [0,0]의 면적은 3.14
Circle [0,1]의 면적은 12.56
Circle [0,2]의 면적은 28.26
Circle [1,0]의 면적은 50.24
Circle [1,1]의 면적은 78.5
Circle [1,2]의 면적은 113.04

// 예제 4-5 : 정수형 공간의 동적 할당 및 반환 예
#include <iostream>
using namespace std;

int main() {
    int *p;

    p = new int;
    if(!p) {
        cout << "메모리를 할당할 수 없습니다.";
        return 0;
    }

    *p = 5;
    int n = *p;
    cout << "*p = " << *p << '\n';
    cout << "n = " << n << '\n';

    delete p;
}

// 실행 결과
*p = 5
n = 5

// 예제 4-6 : 정수형 배열의 동적 할당 및 반환
#include <iostream>
using namespace std;

int main() {
    cout << "입력할 정수의 개수는?";
    int n;
    cin >> n;
    if(n <= 0) return 0;
    int *p = new int [n];
    if(!p) {
        cout << "메모리를 할당할 수 없습니다.";
        return 0;
    }

    for(int i=0; i<n; i++) {
        cout << i+1 << " 번째 정수: ";
        cin >> p[i];
    }

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += p[i];
    cout << "평균 = " << sum/n << endl;

    delete [] p;
}

// 실행 결과
입력할 정수의 개수는?4
1 번째 정수: 4
2 번째 정수: 20
3 번째 정수: -5
4 번째 정수: 9
평균 = 7

// 예제 4-7 : Circle 객체의 동적 생성 및 반환
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
    Circle *p, *q;
    p = new Circle;
    q = new Circle(30);
    cout << p->getArea() << endl << q->getArea() << endl;
    delete p;
    delete q;
}

// 실행 결과
생성자 실행 radius = 1
생성자 실행 radius = 30
3.14
2826
소멸자 실행 radius = 1
소멸자 실행 radius = 30

// 예제 4-8 : Circle 객체의 동적 생성과 반환 응용
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRaius(int r) { radius = r; }
    double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
    int radius;
    while(true) {
        cout << "정수 반지름 입력(음수이면 종료)>> ";
        cin >> radius;
        if(radius < 0) break;
        Circle *p = new Circle(radius);
        cout << "원의 면적은 " << p->getArea() << endl;
        delete p;
    }
}

// 실행 결과
정수 반지름 입력(음수이면 종료)>> 5
생성자 실행 radius = 5
원의 면적은 78.5
소멸자 실행 radius = 5
정수 반지름 입력(음수이면 종료)>> 9
생성자 실행 radius = 9
원의 면적은 254.34
소멸자 실행 radius = 9
정수 반지름 입력(음수이면 종료)>> -1

// 예제 4-9 : Circle 배열의 동적 생성 및 반환
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14*radius*radius; }
};

Circle::Circle() {
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
    Circle *pArray = new Circle[3];

    pArray[0].setRadius(10);
    pArray[1].setRadius(20);
    pArray[2].setRadius(30);

    for(int i=0; i<3; i++) {
        cout << pArray[i].getArea() << "\n";
    }
    Circle *p = pArray;
    for(int i=0; i<3; i++) {
        cout << p->getArea() << "\n";
        p++;
    }

    delete [] pArray;
}

// 실행 결과
생성자 실행 radius = 1
생성자 실행 radius = 1
생성자 실행 radius = 1
314
1256
2826
314
1256
2826
소멸자 실행 radius = 30
소멸자 실행 radius = 20
소멸자 실행 radius = 10

// 예제 4-10 : 객체 배열의 동적 생성과 반환 응용
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle();
    ~Circle() {};
    void setRadius(int r) {radius = r;}
    double getArea() {return 3.14*radius*radius;}
};

Circle::Circle() {
    radius = 1;
}

int main() {
    cout << "생성하고자 하는 원의 개수?";
    int n, radius;
    cin >> n;

    Circle *pArray = new Circle[n];

    for(int i=0; i<n; i++) {
        cout << "원" << i+1 << ": ";
        cin >> radius;
        pArray[i].setRadius(radius);
    }

    for(int i=0; i<n; i++) {
        cout << pArray[i].getArea() << " ";
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        double area = pArray[i].getArea();
        if(area >= 100 && area <= 200) {
            count ++;
        }
    }

    cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;

    delete [] pArray;
}

// 실행 결과
생성하고자 하는 원의 개수?4
원1: 5
원2: 6
원3: 7
원4: 8
78.5 113.04 153.86 200.96 
면적이 100에서 200 사이인 원의 개수는 2
