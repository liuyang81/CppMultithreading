#include <functional>
#include <iostream>

double my_divide (double x, double y) {return x/y;}
int main()
{
    /* std::bind函数定义在头文件functional中，是一个函数模板，它就像一个函数适配器，接受一个可调用对象（callable object），生成一个新的可调用对象来“适应”原对象的参数列表。
    * 一般而言，我们用它可以把一个原本接收N个参数的函数fn，通过绑定一些参数，返回一个接收M个（M可以大于N，但这么做没什么意义）参数的新函数。
    * 同时，使用std::bind函数还可以实现参数顺序调整等操作。
    */
    //auto fn_half = std::bind (my_divide,std::placeholders::_1,2);  //std::placeholders::_1
    //std::cout << fn_half(10) << '\n'; 

    //auto fn_half = std::bind (my_divide,100,std::placeholders::_1);  //std::placeholders::_1
    //std::cout << fn_half(5) << '\n'; 

    auto fn_half = std::bind (my_divide,std::placeholders::_1,std::placeholders::_2);  //std::placeholders::_1
    std::cout << fn_half(100,5) << '\n'; 
}