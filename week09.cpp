// 예제 6-2
#include <iostream>
using namespace std;

int sum(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {   
        sum += i;
    }

    return sum;
}

int  sum(int a) {
    int sum = 0;
    for (int i = 0; i <= a; i++) {   
        sum += i;
    }

    return sum;
}

int main() {
    cout << sum(3,5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;
}

// 실행 결과
12
6
5050

// 예제 6-3
#include <iostream>
#include <string>
using namespace std;

void star(int a=5);
void msg(int id, string text="");

void star(int a) {
    for(int i=0; i<a; i++)
        cout << '*';
    cout << endl;
}

void msg(int id, string text) {
    cout << id << ' ' << text << endl;
}

int main() {
    star();
    star(10);

    msg(10);
    msg(10, "Hello");
}

// 실행 결과
*****
**********
10 
10 Hello

// 예제 6-4
#include <iostream>
using namespace std;

void f(char c, int line=1);

void f(char c=' ', int line) {
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < 10; j++)
            cout << c;
        cout << endl;
    }
}

int main() {
    f();
    f('%');
    f('@', 5);
}

// 실행 결과
          
%%%%%%%%%%
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@

// 예제 6-5
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') {
    for(int i=0; i<n; i++) cout << c;
    cout << endl;
}

int main() {
    fillLine();
    fillLine(10, '%');
}

// 실행 결과
*************************
%%%%%%%%%%

// 예제 6-6
#include <iostream>
using namespace std;

class MyVector{
    int *p;
    int size;
public:
    MyVector(int n = 100) {
        p = new int[n];
        size = n;
    }
    ~MyVector() { delete [] p; }
};

int main() {
    MyVector *v1, *v2;
    v1 = new MyVector();
    v2 = new MyVector(1024);

    delete v1;
    delete v2;
}
