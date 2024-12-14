// 예제 10-6
#include <iostream>
using namespace std;

template <class T>
class MyStack {
    int tos;
    T data [100];
public:
    MyStack();
    void push(T element);
    T pop();
};

template <class T> 
MyStack<T>::MyStack() {
    tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
    if(tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
 }

template <class T>
T MyStack<T>::pop() {
    T retData;
    if(tos == -1) {
        cout << "stack empty";
        return 0;
    }
    retData = data[tos--];
    return retData;
  }

  int main() {
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << endl;

    MyStack<double> dStack;
    dStack.push(3.5);
    cout << dStack.pop() << endl;

    MyStack<char> *p = new MyStack<char>();
    p->push('a');
    cout << p->pop() << endl;
    delete p;
  }

// 실행 결과
3
3.5
a

// 예제 10-7
#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

template <class T>
class MyStack {
    int tos;
    T data [100];
public:
    MyStack();
    void push(T element);
    T pop();
};

template <class T> 
MyStack<T>::MyStack() {
    tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
    if(tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
 }

template <class T>
T MyStack<T>::pop() {
    T retData;
    if(tos == -1) {
        cout << "stack empty";
        return 0;
    }
    retData = data[tos--];
    return retData;
  }

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) { this->x = x; this->y =y; }
    void show() { cout << '(' << x << ',' << y << ')' << endl; }
};

int main() {
    MyStack<int*> ipStack;
    int *p = new int [3];
    for(int i=0; i<3; i++) p[i] = i*10;
    ipStack.push(p);
    int *q = ipStack.pop();
    for(int i=0; i<3; i++) cout << q[i] << ' ';
    cout << endl;
    delete [] p;

    MyStack<Point> pointStack;
    Point a(2,3), b;
    pointStack.push(a);
    b = pointStack.pop();
    b.show();

    MyStack<Point*> pStack;
    pStack.push(new Point(10,20));
    Point* pPoint = pStack.pop();
    pPoint->show();

    MyStack<string> stringStack;
    string s="c++";
    stringStack.push(s);
    stringStack.push("java");
    cout << stringStack.pop() << ' ';
    cout << stringStack.pop() << endl;
}

// 실행 결과 
0 10 20 
(2,3)
(10,20)
java c++

// 예제 10-8
#include <iostream>
using namespace std;

template <class T1, class T2>
class GClass {
    T1 data1;
    T2 data2;
public:
    GClass();
    void set(T1 a, T2 b);
    void get(T1 &a, T2 &b);
};

template <class T1, class T2>
GClass<T1, T2>::GClass() {
    data1 = 0; data2 = 0;
}

template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
    data1 = a; data2 = b;
}

template <class T1, class T2>
void GClass<T1, T2>::get(T1 & a, T2 & b) {
    a = data1; b = data2;
}

int main() {
    int a;
    double b;
    GClass<int, double> x;
    x.set(2, 0.5);
    x.get(a, b);
    cout << "a=" << a << '\t' << "b=" << b << endl;

    char c;
    float d;
    GClass<char, float> y;
    y.set('m', 12.5);
    y.get(c, d);
    cout << "c=" << c << '\t' << "d=" << d << endl;
}

// 실행 결과
a=2     b=0.5
c=m     d=12.5

// 예제 10-9
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    v[0] = 10;
    int n = v[2];
    v.at(2) = 5;

    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

// 실행 결과
1 2 3 
10 2 5 

// 예제 10-10
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하라" << endl;
    for(int i=0; i<5; i++) {
        cout << i+1 << ">>";
        getline(cin, name);
        sv.push_back(name);
    }
    name = sv.at(0);
    for(int i=1; i<sv.size(); i++) {
        if (name < sv[i])
            name = sv[i];
    }
    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << endl;
}

// 실행 결과
이름을 5개 입력하라
1>>황기태
2>>이재문
3>>김남윤
4>>한원선
5>>애슐리
사전에서 가장 뒤에 나오는 이름은 황기태

// 예제 10-11
// 실행 결과
// 예제 10-12
// 실행 결과
// 예제 10-13
// 실행 결과
// 예제 10-14
// 실행 결과
// 예제 10-15
// 실행 결과
// 예제 10-16
// 실행 결과
// 예제 10-17
// 실행 결과
// 예제 10-18
// 실행 결과
// 예제 10-19
// 실행 결과
// 예제 10-20
// 실행 결과
