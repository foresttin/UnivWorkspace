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
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;

    for(it=v.begin(); it != v.end(); it++) {
        int n = *it;
        n = n*2;
        *it = n;
    }

    for(it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << endl;
}

// 실행 결과
2 4 6 
    
// 예제 10-12
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
map<string, string> dic; // 맵 컨테이너 dic 생성. 키는 영어 단어, 값은 한글 단어

// 단어 3개를 map에 저장
dic.insert(make_pair("love", "사랑")); // ("love", "사랑") 저장
dic.insert(make_pair("apple", "사과")); // ("apple", "사과") 저장
dic["cherry"] = "체리"; // ("cherry", "체리") 저장

cout << "저장된 단어 개수 " << dic.size() << endl;

string eng;
while (true) {
    cout << "찾고 싶은 단어>> ";
    getline(cin, eng); // 사용자로부터 키 입력
    if (eng == "exit")
        break; // "exit"이 입력되면 종료

    if(dic.find(eng) == dic.end()) // eng '키'를 끝까지 찾았는데 없음
        cout << "없음" << endl;
    else
        cout << dic[eng] << endl; // dic에서 eng의 값을 찾아 출력
    }
    cout << "종료합니다..." << endl;
}

// 실행 결과
저장된 단어 개수 3
찾고 싶은 단어>> apple
사과
찾고 싶은 단어>>  lov
없음
찾고 싶은 단어>> love
사랑
찾고 싶은 단어>> exit
종료합니다...
    
// 예제 10-13
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v; // 정수 벡터 생성
    cout << "5개의 정수를 입력하세요>> ";
    for(int i=0; i<5; i++) {
        int n;
        cin >> n;
        v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
    }

    // v.begin()에서 v.end() 사이의 값을 오름차순으로 정렬
    // sort() 함수의 실행 결과 벡터 v의 원소 순서가 변경됨
    sort(v.begin(), v.end());

    vector<int>::iterator it; // 벡터 내의 원소를 탐색하는 iterator 변수 선언
    
    for(it=v.begin(); it != v.end(); it++) // 벡터 v의 모든 원소 출력
        cout << *it << ' ';
    cout << endl;
}

// 실행 결과
5개의 정수를 입력하세요>> 30 -7 250 6 120
-7 6 30 120 250 
    
// 예제 10-14
#include <iostream>
#include <vector>
using namespace std;

int square(int x) { return x*x; }

int main() {
    // 기본 타입 선언에 auto 활용
    auto c = 'a'; // c는 char 타입으로 결정
    auto pi = 3.14; // pi은 double 타입으로 결정
    auto ten = 10; // ten은 int 타입으로 결정
    auto *p = &ten; // 변수 p는 int* 타입으로 결정
    cout << c << " " << pi << " " << ten << " " << *p << endl;

    // 함수의 리턴 타입으로 추론
    auto ret = square(3); // square() 함수의 리턴 타입이 int 이므로 ret는 int로 결정
    cout << *p << " " << ret << endl;

    vector<int> v = { 1,2,3,4,5 }; //벡터 v에 5개의 원소, 1,2,3,4,5 삽입
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " "; // 1 2 3 4 5 출력
    cout << endl;
    
    // 템플릿에 auto를 사용하여 간소화
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " "; // 1 2 3 4 5 출력
}

// 실행 결과
a 3.14 10 10
10 9
1 2 3 4 5
1 2 3 4 5

// 예제 10-15
#include <iostream>
using namespace std;
int main() {
// 람다 함수 선언과 동시에 호출(x=2, y=3 전달)
[](int x, int y) { cout << "합은 " << x + y; } (2, 3); // 5 출력
}

// 실행 결과
합은 5
    
// 예제 10-16
#include <iostream>
#include <string>
using namespace std;

int main() {
    auto love = [](string a, string b) {
                    cout << a << "보다 " << b << "가 좋아" << endl;
                };
    love("돈", "너"); // 람다식 호출
    love("냉면", "만두"); // 람다식 호출
}

// 실행 결과
돈보다 너가 좋아
냉면보다 만두가 좋아

// 예제 10-17
#include <iostream>
using namespace std;

int main() {
    double pi = 3.14; // 지역 변수
    auto calc = [pi](int r) -> double { return pi*r*r; };
    cout << "면적은 " << calc(3); // 람다식 호출. 28.26출력
}

// 실행 결과
면적은 28.26
    
// 예제 10-18
#include <iostream>
using namespace std;

int main() {
    int sum = 0; // 지역 변수
    [&sum](int x, int y) { sum = x + y; } (2, 3); // 합 5를 지역변수 sum에 저장
    cout << "합은 " << sum;
}

// 실행 결과
합은 5
    
// 예제 10-19
#include <iostream>
#include <vector>
#include <algorithm> // for_each() 알고리즘 함수를 사용하기 위함
using namespace std;

void print(int n) {
    cout << n << " ";
}

int main() {
    vector<int> v = { 1, 2, 3, 4, 5 };
    // for_each()는 벡터 v의 첫번째 원소부터 끝까지 검색하면서,
    // 각 원소에 대해 print(int n) 호출. 매개 변수 n에 각 원소 값 전달
    for_each(v.begin(), v.end(), print);
}

// 실행 결과
1 2 3 4 5
    
// 예제 10-20
#include <iostream>
#include <vector>
#include <algorithm> // for_each() 알고리즘 함수를 사용하기 위함
using namespace std;

int main() {
    vector<int> v = { 1, 2, 3, 4, 5 };
    // for_each()는 벡터 v의 첫번째 원소부터 끝까지 검색하면서,
    // 각 원소에 대해 3번째 매개변수인 람다식 호출. 매개변수 n에 각 원소 값 전달
    for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
}

// 실행 결과
1 2 3 4 5
