#include <iostream>

using namespace std;

class Location01 {
public:
  Location01(int locX = 0, int locY = 0) {
    cout << "带参数构造函数" << endl;
    x = locX;
    y = locY;
  }

  Location01(const Location01 &loc) {
    cout << "拷贝构造函数" << endl;
    this->x = ((Location01 &) loc).getX();
    this->y =  ((Location01 &) loc).getY();
  }

  ~Location01() {
    cout << "析构函数" << endl;
    this->x = 0;
    this->y = 0;
  }

  int getX() { return x; }

  int getY() { return y; }

private:
  int x;
  int y;
};

void f(Location01 p) {
  cout << "Function: " << p.getX() << ", " << p.getY() << endl;
}

void mainobjplay() {
  Location01 A(1, 2);
  f(A);
}

int main03() {
  cout << " ~~ main ~~ " << endl;

  mainobjplay();

  return 0;
}