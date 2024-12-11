// 예제 9-6
#include <iostream>
using namespace std;

class Calculator {
public:
    virtual int add(int a, int b) = 0;
    virtual int subtract(int a, int b) = 0;
    virtual double average(int a [], int size) = 0;
    virtual ~Calculator() {}
};

class GoodCalc : public Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    double average(int a [], int size) {
        double sum = 0;
        for(int i = 0; i<size; i++)
            sum += a[i];
        return sum/size;
    }
};

int main() {
    int a[] = {1,2,3,4,5};
    Calculator *p = new GoodCalc();
    cout << p->add(2,3) << endl;
    cout << p->subtract(2,3) << endl;
    cout << p->average(a,5) << endl;
    delete p;
}

// 실행 결과
5
-1
3

// 예제 9-7
#include <iostream>
using namespace std;

class Calculator {
    void input() {
        cout << "정수 2개를 입력하세요>> ";
        cin >> a >> b;
    }
protected:
    int a, b;
    virtual int calc(int a, int b) = 0;
public:
    void run() {
        input();
        cout << "계산된 값은 " << calc(a,b) << endl;
    }
};

class Adder : public Calculator {
protected:
    int calc(int a, int b) {
        return a + b;
    }
};

class Subtractor : public Calculator {
protected:
    int calc(int a, int b) {
        return a - b;
    }
};

int main() {
    Adder adder;
    Subtractor subtractor;
    adder.run();
    subtractor.run();
}

// 실행 결과
정수 2개를 입력하세요>> 5 3
계산된 값은 8
정수 2개를 입력하세요>> 5 3
계산된 값은 2

// 예제 10-1
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius=1) { this->radius = radius; }
    int getRadius() { return radius; }
};

template <class T>
void myswap(T & a, T & b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a=4, b=5;
    myswap(a,b);
    cout << "a= " << a << ", " << "b= " << b << endl;

    double c=0.3, d=12.5;
    myswap(c,d);
    cout << "c= " << c << ", " << "d= " << d << endl;

    Circle donut(5), pizza(20);
    myswap(donut, pizza);
    cout << "donut반지름=" << donut.getRadius() << ", ";
    cout << "pizza반지름=" << pizza.getRadius() << endl;
}

// 실행 결과
a= 5, b= 4
c= 12.5, d= 0.3
donut반지름=20, pizza반지름=5

// 예제 10-2
#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {
    int a=20, b=50;
    char c='a', d='z';
    cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << endl;
    cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << endl;
}

// 실행 결과
bigger(20, 50)의 결과는 50
bigger('a', 'z')의 결과는 z

// 예제 10-3
#include <iostream>
using namespace std;

template <class T>
T add(T data [], int n) {
    T sum = 0;
    for(int i=0; i<n; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    int x[] = {1,2,3,4,5};
    double d[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

    cout << "sum of x[] = " << add(x, 5) << endl;
    cout << "sum of d[] = " << add(d, 6) << endl;
}

// 실행 결과
sum of x[] = 15
sum of d[] = 23.7

// 예제 10-4
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src [], T2 dest [], int n) {
    for(int i=0; i<n; i++)
        dest[i] = (T2)src[i];
}

int main() {
    int x[] = {1,2,3,4,5};
    double d[5];
    char c[5] = {'H', 'e', 'l', 'l', 'o'}, e[5];

    mcopy(x, d, 5);
    mcopy(c, e, 5);

    for(int i=0; i<5; i++) cout << d[i] << ' ';
    cout << endl;
    for(int i=0; i<5; i++) cout << e[i] << ' ';
    cout << endl;
}

// 실행 결과
1 2 3 4 5 
H e l l o 
