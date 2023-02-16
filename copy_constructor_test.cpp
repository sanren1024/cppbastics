#include <iostream>

using namespace std;

class B // 2
{       //
public:
  B() { cout << "无参构造函数" << endl; }

  B(int a) {
    cout << "带参构造函数" << endl;
    m_a = a;
  }

  B(const B &target) { this->m_a = ((B &)target).getA(); }

  B(B &target) { this->m_a = target.getA(); }

  int getA() { return m_a; }

private:
  int m_a = 0;
};                                                       // 4
B func(const B &rhs) {                                   // 5
  printf("func(): %p, a=%d\n", &rhs, ((B &)rhs).getA()); //
  return rhs;                                            // 6
} // 7

class Complex {
public:
  double real, imag;
  Complex(double r, double i) {
    real = r;
    imag = i;
  }

  Complex(const Complex &c) {
    real = c.real;
    imag = c.imag;
    cout << "Copy Constructor called" << endl;
  }
};

int main06() {
  // B b1(2), b2(5);                       // 9
  // printf("main() b1: %p, a=%d\n", &b1, b1.getA()); //
  // printf("main() b2: %p, a=%d\n", &b2, b2.getA()); //
  // b2 = func(b1);                  // 10
  // printf("main() b2: %p, a=%d\n", &b2, b2.getA());
  //
  Complex c1(1, 2);
  Complex c2(c1); // 用复制构造函数初始化c2
  printf("c1: %p, c2: %p\n", &c1, &c2);
  cout << c2.real << ", " << c2.imag << endl; // 输出 1,2
  return 0;
}