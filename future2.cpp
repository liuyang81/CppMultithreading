#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <vector>

inline int func(int x)
{
    return x + 6;
}

int main()
{
    /*
    * std::packaged_task包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果。
    * std::packaged_task将其包装的可调用对象的执行结果传递给一个std::future对象，与
    * std::promise某种程度上是很像的，promise保存一个共享状态的值，而package_task保存的是一个函数。
    */
    std::packaged_task<int(int)> tsk(func);
    std::future<int> fut = tsk.get_future(); //获取future绑定起来
    
    std::thread(std::move(tsk), 2).detach();//直接将task转移作为线程函数使用

    auto value = fut.get();
    std::cout << "result:" << value << std::endl;
    
    system("pause");

    return 0;
}