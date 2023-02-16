#include <iostream>

using namespace std;

class StaticTest {

public:
  int getC() { return c; }

  void addC() { c = c + 1; }

protected:
private:
  // c++ 声明的私有static变量初始化使用域操作符进行，并且需要类型声明
  static int c;
};

// 对static变量进行初始化，需要有类型声明
int StaticTest::c = 100;

int main() {
  cout << " ~~~ static variables ~~~" << endl;

  StaticTest st1;
  // 调用私有的static变量是不可行的。
  //   cout << "域操作符：" << StaticTest::c << endl;

  return 0;
}