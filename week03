// 예제 2-2
#include <iostream>

double area(int r);

double area(int r) {
    return 3.14*r*r;
}

int main() {
    int n=3;
    char c='#';
    std::cout << c << 5.5 << '-' << n << "hello" << true << std::endl;
    std::cout << "n + 5 = " << n + 5 << '\n';
    std::cout << "면적은 " << area(n);
}

// 실행 결과
#5.5-3hello1
n + 5 = 8
면적은 28.26

// 예제 2-3
#include <iostream>
using namespace std;

int main() {
    cout << "너비를 입력하세요>>";

    int width;
    cin >> width;

    cout << "높이를 입력하세요>>";

    int height;
    cin >> height;

    int area = width*height;
    cout << "면적은 " << area << "\n";3
}

// 실행 결과
너비를 입력하세요>>3
높이를 입력하세요>>5
면적은 15

// 예제 2-4
#include <iostream>
using namespace std;

int main() {
    cout << "이름을 입력하세요>>";

    char name[11];
    cin >> name;

    cout << "이름은 " << name << "입니다\n";
}

// 실행 결과
이름을 입력하세요>>이수빈
이름은 이수빈입니다

// 예제 2-5
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char password[11];
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while(true) {
        cout << "암호>>";
        cin >> password;
        if(strcmp(password, "C++") == 0) {
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        else
            cout << "암호가 틀립니다~~" << endl;
    }
}

// 실행 결과
프로그램을 종료하려면 암호를 입력하세요.
암호>>Java
암호가 틀립니다~~
암호>>C
암호가 틀립니다~~
암호>>C++
프로그램을 정상 종료합니다.

// 예제 2-6
#include <iostream>
using namespace std;

int main() {
    cout << "주소를 입력하세요>>";

    char address[100];
    cin.getline(address, 100, '\n');

    cout << "주소는 " << address << "입니다\n";
}

// 실행 결과
주소를 입력하세요>>컴퓨터시 프로그램구 C++동 스트링 1-1          
주소는 컴퓨터시 프로그램구 C++동 스트링 1-1입니다

// 예제 2-7
#include <iostream>
#include <string>
using namespace std;

int main() {
    string song("Falling in love with you");
    string elvis("Elvis Presley");
    string singer;

    cout << song + "를 부른 가수는";
    cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";

    getline(cin, singer);
    if(singer == elvis)
        cout << "맞았습니다.";
    else
        cout << "틀렸습니다. " + elvis + "입니다." << endl;
}

// 실행 결과
Falling in love with you를 부른 가수는(힌트 : 첫글자는 E)?Elvis Pride
틀렸습니다. Elvis Presley입니다.
