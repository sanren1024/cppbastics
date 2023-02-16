#include <iostream>

using namespace std;

class MyTest {
public:
  MyTest(int a, int b) {
    this->a = a;
    this->b = b;

    MyTest(a, b, 100);
  }

  MyTest(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  int getC() { return c; }

private:
  int a;
  int b;
  int c;
};

int main10() {

  MyTest t1(10, 20);
  cout << "c:" << t1.getC() << endl;
  //   system("pause");
  return 0;
}