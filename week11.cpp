// 예제 8-1
#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    void set(int x, int y) { this->x = x; this->y = y;}
    void showPoint(){
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) { this->color = color; }
    void showColorPoint();
};

void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint();
}

int main() {
    Point p;
    ColorPoint cp;
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();
}

// 실행 결과
Red:(3,4)

// 예제 8-3
#include <iostream>
#include <string>
using namespace std;

class TV {
    int size;
public:
    TV() { size = 20; }
    TV(int size) { this-> size = size; }
    int getSize() { return size; }
};

class WideTV : public TV { 
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size) {
        this->videoIn = videoIn;
    }
    bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
    string ipAddr;
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true) {
        this->ipAddr = ipAddr;
    }
    string getAddr() { return ipAddr; }
};

int main() {
    SmartTV htv("192.0.0.1", 32);
    cout << "size=" << htv.getSize() << endl;
    cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
    cout << "IP=" << htv.getAddr() << endl;
}

// 실행 결과
size=32
videoIn=true
IP=192.0.0.1

// 예제 8-7
#include <iostream>
using namespace std;

class Adder {
protected:
    int add(int a, int b) { return a+b; }
};

class Subtractor {
protected:
    int minus(int a, int b) { return a-b; }
};

class Calculator : public Adder, public Subtractor {
public:
    int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
    int res=0;
    switch(op) {
        case '+' : res = add(a, b); break;
        case '-' : res = minus(a, b); break;
    }
    return res;
}

int main() {
    Calculator handCalculator;
    cout << "2 + 4 = "
        << handCalculator.calc('+', 2, 4) << endl;
    cout << "100 - 8 = "
        << handCalculator.calc('-', 100, 8) << endl;
}

// 실행 결과
2 + 4 = 6
100 - 8 = 92
