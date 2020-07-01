#include <iostream>
#include <string>
using namespace std;

int main() {
    //explicit 不能隐式类型转换
    //void fun(int T)
    //void fun(int& T)
    //void fun(int && T)
    //void fun(int* t)
    //http://blog.gssxgss.me/cpp11-move-constructor-and-std-move-1/
    //https://blog.csdn.net/daaikuaichuan/article/details/88371948?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase
    //https://www.cnblogs.com/meixiaogua/p/9924623.html
    //int i = 10;
    // 右值引用-右值
    //int&& rr = 42;
    //int&& rr1 = std::move(i);
    //const左值引用--右值
    //const int& c = 42;
    //左值引用--左值
    //int& lr = rr;
    //注意：右值引用也是变量，所以rr是左值。

    //1.如果把左值引用理解为变量的别名，那么右值引用就是资源的别名。通过右值引用可以直接操作藏在对象名后面的对象资源。
    #if 0
    string a = "aaa";
    string&& r = std::move(a);
    r = "rrr";
    cout << a << endl;
    #endif

    //2.作为move constructor 和 move assignment的参数。
    #if 1
    string a("aaa");
    string b(std::move(a));//移动move构造
    cout << "move construct b from a, a:" << a << "\tb:" << b << endl;
    string c("ccc");
    c = std::move(b);//移动move赋值
    cout << "move assignment c from b, b:" << b << "\tc:" << c << endl;//可见，string的拷贝赋值里，对b和c的资源指针做了swap
    #endif

}