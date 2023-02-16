#include <iostream>

using namespace std;

class Location {
public:
  Location(int locX = 0, int locY = 0) {
    cout << "带参数构造函数" << endl;
    x = locX;
    y = locY;
  }

  Location(const Location &loc) {
    cout << "拷贝构造函数" << endl;
    this->x = loc.x;
    this->y = loc.y;
  }

  ~Location() {
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

Location create() {
  Location loc(3, 4);
  printf("create()内loc地址：%p\n", &loc);
  return loc; // 调用 带参数构造函数
}

void display() {

  // 测试证明，直接声明变量被函数返回赋值，不调用拷贝构造函数
  Location obj = create();
  printf("display()内obj地址：%p\n", &obj);
}

int main07() {
  cout << " ~~ main ~~ " << endl;
  display();
  // Location obj1;
  // printf("main()内pre_obj1地址：%p\n", &obj1);
  // obj1 = create();

  // printf("main()内post_obj1地址：%p\n", &obj1);

  return 0;
}