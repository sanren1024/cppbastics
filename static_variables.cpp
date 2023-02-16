#include <iostream>

using namespace std;

class StaticTest {

public:
  // 静态成员函数
  static int getC() { return c; }

  static void printC() {
    cout << "print static int c: " << c << endl;

    // 静态成员函数内不能访问非静态成员变量
    // cout << "在静态函数内访问普通成员变量：" << a << endl;
  }

  void addC() { c = c + 1; }

protected:
private:
  int a;

  // c++ 声明的私有static变量初始化使用域操作符进行，并且需要类型声明
  static int c;
};

// 对static变量进行初始化，需要有类型声明
int StaticTest::c = 100;

int main11() {
  cout << " ~~~ static variables ~~~" << endl;

  StaticTest st1;
  // 调用私有的static变量是不可行的。
  //   cout << "域操作符：" << StaticTest::c << endl;

  // 调用函数访问静态变量，需要函数对应的也是static函数
  cout << "1. 域操作符：" << StaticTest::getC() << endl;

  cout << "1. 通过对象访问静态变量：" << st1.getC() << endl;

  // 调用addC()函数对static变量c自增1
  st1.addC();

  cout << "2. 域操作符：" << StaticTest::getC() << endl;

  cout << "2. 通过对象访问静态变量：" << st1.getC() << endl;

  StaticTest st2;
  cout << "3. 通过对象访问静态变量：" << st2.getC() << endl;

  return 0;
}