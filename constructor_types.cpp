#include <iostream>

using namespace std;

class Test
{
public:
        Test()
        {
            cout << "无参数构造函数" << endl;
        }
        Test(int a, int b)
        {
            cout << "有参构造函数" << endl;
            m_a = a;
            m_b = b;
        }
        Test(const Test &source)
        {
            cout << "赋值/拷贝构造函数" << endl;
        }

    void printVariables()
    {
        cout << "m_a=" << m_a << ", m_b=" << m_b << endl;
    }

private:
    int m_a;
    int m_b;
};

void display()
{
    // Test t1; // 调用无参数构造函数

    Test t2(1, 2); // 有参数构造函数，调用方法前需要提供参数值
    // Test t3();
    // t3.printVariables(); // 错误方法

    // Test t4 = (1, 2); // 在VS中可以编译通过。在使用g++编译时，错误。
    //
    // Test t5 = 5;  在VS中可以编译通过。在使用g++编译时，错误。
    //

    // cout << "sizeof Test:" << sizeof(Test) << endl;
    // t1 = t2;
    Test t6 = t2;
    printf("t6 addr: %p\n", &t6);
    // printf("t2 addr: %p\n", &t2);

}

int main02()
{
    display();

    cout << "vscode 第一个程序" << endl;
    return 0;
}