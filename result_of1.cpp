#include <functional>
#include <iostream>

int main()
{
    /*
    * 1. 追踪返回类型的函数声明
    * int func(char *ptr,int val);
    * 2. 追踪返回类型的函数声明：
    * auto func(char *ptr.int val)->int;
    *template <typename F, typename... Args>
    *auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
    *auto enqueue(F&& f, Args&&... args) -> std::future<decltype(f(args...))>
    *{...}
    * https://blog.csdn.net/qq_31175231/article/details/77165279?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase
    */
    #if 1
    auto MyFunc = [] (int x, int y) -> int {return x+y;};
    //typedef std::result_of<MyFunc(int, int)>::type MyType;
    //std::function<int(int, int)> func = [] (int x, int y) -> int {return x+y;};
    typedef decltype(MyFunc(1, 2)) MyType;
    #else
    typedef int(*MyFunc)(int, int);
    //auto MyFunc = [] (int x, int y) -> int {return x+y;};
    //typedef MyFunc  [](int x, int y) -> int;
    //std::function<int(int, int)> MyFunc = [] (int x, int y) -> int {return x+y;};
    typedef std::result_of<MyFunc(int, int)>::type MyType;
    #endif
    std::cout << "resule type of totalAB is int: " << std::is_same<int, MyType>::value << std::endl;
    return 0;
}